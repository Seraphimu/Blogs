### 【数据结构】用C语言实现单链表及其常见操作

链表是一种常用的基础数据结构，可以快速插入和删除数据，但是不能随机访问。

那么它在内存中是怎么存储的呢？它和数组不同，数组在内存中是连续存储的，而链表不一定是连续的，它们之间是通过`指针`来连接的。

`指针` 是C语言中最重要的特性之一。那么，什么是指针？说白了就是数据在内存中存放的`地址`，可以理解为数据在内存中住的哪一栋，几零几。

链表中的每个元素都有数据域和指针域，数据域用于存放数据，指针域用于存放指向下一个元素的`指针`，即下一个元素在内存中的位置。

在链表中，指向第一个元素的指针，称为头指针。

链表的结束标记是空指针 `NULL`，当我们遍历表时发现当前指针为 `NULL`，那就说明，这里是链表的结尾。

好，接下来，我们来一步一步地实现链表。

#### 结构

链表的数据结构如下：

```c
typedef int SLDataType;
typedef struct LinkedList {
    SLDataType data;
    struct LinkedList * next;
}SL;
```

其中 `struct LinkedList * next` 这个套娃语句可能有点糊涂人。这就是上文中提到的指针域，如你所见，它指向了和自己相同的数据类型，请看下图。

![](https://img2023.cnblogs.com/blog/2716741/202403/2716741-20240330214633954-2053775833.png)

图中的每一个小框框就是链表中的一个元素（常被叫结点，也有叫节点的），然后我们发现每个小框框里面都有两个部分，一个是 `data`，一个是 `next`，这就是数据域和指针域。它们对应我们在结构体中定义的成员变量。

图中的每个 `next` 都指向了下一个元素，末尾是 `NULL`，这样是不是就比较清楚了？

然后我们来看看这个 `typedef`。 `typedef` 是C语言的关键字，用于给数据类型起别名，其语法如下：

```c
typedef <数据类型> <别名>
```

例如：

```c
typedef int mydata;
```

这样操作下来就可以用`mydata`来代替`int`了。

`mydata a = 1;` 和 `int a = 1;` 效果相同。

#### 初始化

现在我们来把一个链表初始化一下，把它的头指针置为空。

```c
void SLInit(SL ** pphead)
{
    *pphead = NULL;
}
```

这个 `**` 是什么呢？这个叫做二级指针，是指向一级指针的指针，这么说有点抽象，来看一个实例：

```c
int a = 114514;
int *p = &a;
int ** pp = &p;

printf("a = %d, p = %p, pp = %p\n", a, p , pp);
printf("&a = %p, p = %p, &p = %p, pp = %p\n", &a, p, &p, pp);
```

``` bash
a = 114514, p = 00000000005ffe84, pp = 00000000005ffe78
&a = 00000000005ffe84, p = 00000000005ffe84, &p = 00000000005ffe78, pp = 00000000005ffe78
```

其中 `p` 是指向整型变量 `a` 的一级指针，`pp` 是指向指针变量 `p` 的二级指针。

输出的结果是多少不重要，重要的是我们发现，`&a == p`，`&p = pp`，用文字描述一下大致就是：变量 `p` 中存放着变量 `a` 的地址，而变量 `pp` 存放着变量 `p` 的地址。这也就意味着 `*pp == p`。

接下来说一下不用二级指针传递参数会怎么样：

```c
void TestSLInit(SL * phead)
{
    phead = NULL;
}
```

表面上看起来没有问题，可是实际上，当我调用 `TestSLInit()`函数的时候是这样的：

调用：
```c
TestSLInit(plist);
```

此时函数内部：
```c
void TestSLInit(SL * phead)
{
    //等价于phead = plist; phead = NULL;
    phead = NULL;
}
```

由于C语言默认是使用 “值传递” 的。也就是说传入参数的时候，C语言会在函数内部创建一个临时变量来接收这个参数，既然是临时变量，那么它的作用域就只能在函数内部。

也就是上述的 `phead` 在程序执行完 `TestSLInit()`函数后就被销毁了，所以，该函数并没有对我的参数 `plist` 做出任何改变。我们来通过打印直观感受一下。

```c
void Test1()
{
    SL * plist;
    printf("plist = %p\n", plist);      //打印一个随机值
    TestSLInit(plist);
    printf("plist = %p\n", plist);      //值不会变
}
```
输出结果：
```bash
plist = 000001f928431350
plist = 000001f928431350
```

可以看出，此时的`TestSLInit()`函数确实没有直到任何作用。

我们来换上 `SLInit()` 函数试试：

```c
void Test1()
{
    SL * plist;
    printf("plist = %p\n", plist);      //打印一个随机值
    SLInit(&plist);                     //注意，这里要传递plist的指针
    printf("plist = %p\n", plist);      //成功置空
}
```

输出：

```bash
plist = 000001418f2d1350
plist = 0000000000000000
```

此时，我们成功地把链表置空了。

#### 尾插

尾插，顾名思义就是从链表的尾部插入数据，所以要在插入之前找到尾结点，然后再把元素接在尾结点的后面。（尾结点就是指针域指向空的那个结点。）

这里我们需要分类讨论，当链表没有元素的时候，即 `plist == NULL` 此时我们要给它分配一个结点，当链表没有元素的时候，我们通过遍历找到它的尾结点，然后将要插入的结点接在后面。

那么问题来了，怎么分配结点呢？怎么找到尾结点呢？

下面是分配结点的函数：

通过参数 `x` 来分配一个数据域为 `x` 指针域为 `NULL` 的结点。再通过 `newNode` 把新结点返回。

```c
SL * SLBuyCapacity(SLDataType x)
{
    SL * newNode = (SL *)malloc(sizeof(SL));        //给新结点分配空间
    
    if (newNode == NULL)                            //判断是否分配成功
    {
        printf("Malloc Failed!\n");
        exit(-1);
    }
    else
    {
        newNode->data = x;                         //给结点的数据域赋值
        newNode->next = NULL;                      //给结点的指针域赋值
    }

    return newNode;                                //返回该结点
}
```

尾插实现

```c
void SLPushBack(SL ** pphead, SLDataType x)
{
    //没有节点的情况
    if (*pphead == NULL)
    {
        *pphead = SLBuyCapacity(x);     //将头指针指向当前分配的新结点
    }
    //其他情况
    else
    {
        SL * tail = *pphead;            //通过tail遍历链表，找到尾结点
        SL * newNode = SLBuyCapacity(x);//分配一个新结点
        while (tail->next != NULL)      //遍历
        {
            tail = tail->next;          //使tail指向下一个结点
        }
        tail->next = newNode;           //把新分配的结点接在表尾
    }
}
```

---

未完，待更新……