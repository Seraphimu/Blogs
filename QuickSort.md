快速排序的主要思想：

- 选取一个数为枢轴`PivotKey`，把序列中比它大的数放在它的其中一侧，把比它小的数放在它的另一侧
- 再选取左右两侧中的任意一侧，做相同的操作，直到把序列中所有的数排序完毕。
  - 比如选左边先进行操作，快速排序将对左侧继续划分成两个子序列，
  - 然后再将左侧的左侧划分成两个子序列，
  - 直到把左侧划分完毕，返回上一层，去处理右侧的序列。

```c

void Swap(int* a, int* b)
{
	int Tmp = *a;
	*a = *b;
	*b = Tmp;
}

int Partition(int Array[], int Low, int High)
{
	int PivotKey = Array[Low];								//选取第1个元素为枢轴
	
	while (Low < High)
	{
		while (Low < High && Array[High] >= PivotKey)		//从右边找小的，交换到左边
		{
			High--;
		}
		Swap(&Array[High], &Array[Low]);

		while (Low < High && Array[Low] <= PivotKey)		//从左边找大的，交换到右边
		{
			Low++;
		}
		Swap(&Array[High], &Array[Low]);
	}

	return Low;
}

void QSort(int Array[], int Low, int High)
{
	int Pivot;

	if (Low < High)
	{
		Pivot = Partition(Array, Low, High);
		QSort(Array, Low, Pivot - 1);			//处理左边
		QSort(Array, Pivot + 1, High);			//处理右边
	}
}
```
