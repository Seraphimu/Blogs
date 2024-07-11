#### 顺序表操作：

ADT:

```c++
#include <iostream>
using namespace std;
#define MAX 100
typedef int DataType;
class Array {
public:
    //存放元素的数组
    DataType A[MAX];
    //元素的个数
    int Size;

    //插入方法
    void ArrayPushBack(DataType X);
    void ArrayPushFront(DataType X);
    void ArrayInsertThisPos(int Pos, DataType X);

    //删除方法
    void ArrayPopBack();
    void ArrayPopFront();
    void ArrayDeleteThisPos(int Pos);

    //排序方法
    void ArraySelectionSort();

    //查找方法
    //查找下标为Pos的元素
    DataType ArraySearchByPos(int Pos);
    //返回欲查找元素的下标，若不存在，则返回-1
    int ArraySearchByValue(DataType X);

    // 查找特殊值
    DataType ArrayFindMax();
    DataType ArrayFindMin();


    // 修改方法，根据下标修改
    void ArrayModifyByPos(int Pos, DataType X);
    // 如果该值在数组中，则修改；若无，返回 -1
    void ArrayModifyByValue(DataType SourceX, DataType X);

    //辅助方法
    //初始化：创建一个空表
    void ArrayInit();
    //打印
    void ArrayPrint();
    //判断表是否满
    bool ArrayIsFull();
    //判断表是否空
    bool ArrayIsEmpty();
    //判断下标是否合法
    bool ArrayPosErr(int Pos);
    //交换两个元素的值
    void Swap(int & a, int & b);
};
```

初始化：

把数组的每一个元素元素置为0，数组大小也置为0

```c++
void Array::ArrayInit() {
    //初始化数组，全0
    memset(A, 0, sizeof(A));
    //初始大小为0
    Size = 0;
}
```

判空：

判断表是否为空，为空返回真，非空返回假。

`Size == 0` 即表长度为0，即表为空。

```c++
bool Array::ArrayIsEmpty() {
    if (Size == 0) {
        return true;
    }
    else {
        return false;
    }
}
```

判满：

`Size == MAX` 即表的长度为 `MAX` ， 即表满。

```c++
bool Array::ArrayIsFull() {
    if (Size == MAX) {
        return true;
    }
    else {
        return false;
    }
}
```

尾插：

先要对表进行一个判断，必须还有空间才能插入，如果还有剩余空间，则插入到最后一个元素之后的位置上，即`Size`，然后`Size`自增。 `Size` 是表的长度，`Size - 1` 是数组最后一位元素的下标。

```c++
void Array::ArrayPushBack(DataType X) {
    //如果表满，无法插入
    if (ArrayIsFull()) {
        cout << "Is Full!" << endl;
        exit(-1);
    }
    //如果表不满，在数组末尾插入元素
    A[Size] = X;
    Size++;
}
```

---

细节：

有时可能会看到顺序表这样分配内存，不使用数组，而使用`malloc()`函数或者其他内存分配函数：

```c++
#define MAX 100
class Array {
    public:
    //存放元素的数组
    DataType * A;
    //元素的个数
    int Size; 
};
Array arr;
arr.A  = (DataType *)malloc(sizeof(DataType) * MAX);
```

使用`malloc()`函数等内存分配函数分配的内存是堆区的，使用数组时，使用的是栈区的内存。栈区的内存比较小，用`malloc()`函数把内存分配在堆区可以节省栈区空间。

笔者一开始觉得这种写法挺多此一举的，后来有一次写了一个超大的结构体数组，然后VS报了一个使用过多栈区空间的警告，请考虑将一些数据移动到推之后，才明白这么写的意义何在。

拓展一些内存方面的概念：

- 栈区：主要用来存放局部变量，函数参数等。

- 堆区：主要用于动态分配内存
- 静态区（数据段）：存放全局变量和静态变量等