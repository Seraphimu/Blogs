void Swap(int * A, int * B)
{
    int Tmp = *A;
    *A = *B;
    *B = Tmp;
}

int Paration(int Array[], int Low, int High)
{
    int PivotKey = Array[Low];

    while (Low < High)
    {
        while (Low < High && Array[High] > PivotKey)
        {
            High--;
        }

        Swap(&Array[High], &Array[Low]);

        while (Low < High && Array[Low] < PivotKey)
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
        Pivot = Paration(Array, Low, High);
        QSort(Array, Low, Pivot);
        QSort(Array, Pivot + 1, High);
    }
}


int main(void)
{
	int Array[] = { 0, 50, 10, 90, 30, 70, 40, 80, 60, 20 };
	int High = sizeof(Array) / sizeof(int) - 1;
	QSort(Array, 1, High);

    return 0;
}
