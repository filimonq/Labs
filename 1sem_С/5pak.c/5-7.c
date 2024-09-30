#include <stdio.h>
#include <string.h>

typedef struct LongNum_s {
    int len;
    int arr[10000]; 
} LongNum;

LongNum multiply(LongNum n1, LongNum n2)
{
    LongNum curr = {0, {0}};
    int len = 0;
    LongNum helper;
    if (n2.len > n1.len)
    {
        helper = n1;
        n1 = n2;
        n2 = helper;
    }
    for (int i = 0; i < n2.len; i++)
    {
        for (int j = 0; j < n1.len; j++)
        {
            curr.arr[i+j] += n1.arr[j] * n2.arr[i];
            curr.arr[i+j+1] += curr.arr[i+j] / 10;
            curr.arr[i+j] %= 10;
        }
    }
    for (int i = 9999; i >= 0; i--)
    {
        if (curr.arr[i] > 0)
        {
            curr.len = i + 1;
            break;
        }
    }
    return curr;
}

void print(LongNum curr)
{
    for (int i = curr.len - 1; i >= 0; i--)
    {
        printf("%d", curr.arr[i]);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char a[1001]={0}, b[1001]={0};
    LongNum ans = {0, {0}};
    LongNum n1 = {0, {0}};
    LongNum n2 = {0, {0}};
    scanf("%s", a);
    scanf("%s", b);
    int len_a = strlen(a);
    int len_b = strlen(b);
    for (int i = 0; i < len_a; i++)
    {
        n1.arr[i] = a[len_a - 1 - i] - '0';
    }
    for (int i = 0; i < len_b; i++)
    {
        n2.arr[i] = b[len_b - 1 - i] - '0';
    }
    n1.len = len_a;
    n2.len = len_b;
    ans = multiply(n1, n2);
    print(ans);
    return 0;
}