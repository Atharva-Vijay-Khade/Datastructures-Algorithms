pair<long long, long long> getMinMax(long long a[], int n)
{

    long long ma = LLONG_MIN;
    long long mi = LLONG_MAX;

    for (int i = 0; i < n; i++)
    {
        ma = max(ma, a[i]);
        mi = min(mi, a[i]);
    }

    return {mi, ma};
}