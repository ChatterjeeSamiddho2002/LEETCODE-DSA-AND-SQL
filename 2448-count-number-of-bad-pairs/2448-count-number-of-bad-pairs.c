int compareNums(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

long long countBadPairs(int *nums, int numsSize)
{
    const int n = numsSize;

    int diffs[n];

    for (int i = 0; i < n; ++i)
    {
        diffs[i] = i - nums[i];
    }

    qsort(diffs, n, sizeof(*diffs), compareNums);

    long long t = 1LL * n * (n - 1) / 2;
    long long m = 0;
    long long c = 1;

    for (int i = 1; i < n; ++i)
    {
        if (diffs[i - 1] == diffs[i - 0])
        {
            m += c;
            c += 1;
        }
        else
        {
            c = 1;
        }
    }

    return t - m;
}