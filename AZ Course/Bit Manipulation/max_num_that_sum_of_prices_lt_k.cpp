#include <bits/stdc++.h>
using namespace std;
long long accumulated_price_till(long long n, int x)
{
    long long ans = 0;
    for (long long i = x; i < 64; i += x)
    {
        long long full_set = (n + 1) / (1LL << (i));
        long long partial_set = (n + 1) % (1LL << (i));
        long long bits_in_full_set = full_set * (1LL << (i - 1));
        long long bits_in_partial_set = max(0LL, partial_set - (1LL << (i - 1)));
        ans += bits_in_full_set + bits_in_partial_set;
    }
    return ans;
}
long long findMaximumNumber(long long k, int x)
{
    long long low = 0, high = 1e15;
    long long ans = 0;
    while (low <= high)
    {
        long long mid = (high + low) / 2;
        if (accumulated_price_till(mid, x) <= k)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t;
    cin >> t;
    while (t--)
    {
        long long k;
        int x;
        cin >> k >> x;
        cout << findMaximumNumber(k, x) << "\n";
    }
    return 0;
}