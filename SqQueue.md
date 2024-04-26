## 用数组实现循环队列

用数组实现循环队列，我们主要要考虑的一个问题就是怎么让它循环，也就是在rear走到数组末尾时跳回开头。

队列结构如下：

```c
typedef int QElemType;
typedef struct SqQueue
{
    //存放队列的数组
    QElemType data[MAX];
	//队列的首尾指针
    int front;
    int rear;
}SqQueue;
```

- 我们可以初始化 `front` 和 `rear` 为0，
- 进队操作先让元素进队，然后再让 `rear + 1`。此时我们发现，除了初始化状态下，`rear` 始终指向队尾元素的后一位。
- 当rear指向数组的最后一位时，即 `rear = MAX - 1` 时，