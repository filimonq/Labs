extern long long prefix[100000];
//выполнить подготовку массива: запускается один раз перед запусками Sum
//здесь arr[0..n) –- это массив A из входного файла
void Init(const int *arr, int n)
{
    prefix[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = arr[i - 1] + prefix[i - 1];
    }
}

//найти сумму элементов A на отрезке [l..r)
//использует данные, посчитанные функцией Init
long long Sum(int l, int r)
{
    return (prefix[r] - prefix[l]);
}