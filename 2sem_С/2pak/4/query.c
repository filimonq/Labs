long long Sum(int l, int r);

long long prefix[100000];

int Query(int fix_l, long long sum, int N)
{
    int l = fix_l;
    int r = N, mid = 0;
    while (r - l > 1)
    {
        mid = (l + r) / 2;
        if (Sum(fix_l, mid) > sum)
        {
            r = mid;
        } else if (Sum(fix_l, mid) < sum)
        {
            l = mid;
        } else
        {
            break;
        }
    }
    // 
    if (Sum(fix_l, mid) > sum)
    {
        while (Sum(fix_l, mid) > sum && mid > 0)
        {
            mid--;
        }
        return mid;
    } else if (Sum(fix_l, mid) <= sum)
    {
        while ((mid + 1 <= N) && (Sum(fix_l, mid + 1) <= sum))
        {
            mid++;
        }
        return mid;
    }
    return mid;
}