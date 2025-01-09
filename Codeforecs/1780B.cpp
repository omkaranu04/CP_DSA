#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long long int ps[n + 1];
        ps[0] = 0;
        for (int i = 1; i < n + 1; i++)
        {
            ps[i] = ps[i - 1] + a[i - 1];
        }
        long long int max = INT_MIN;
        for (int i = 1; i <= n - 1; i++)
        {
            long long int s1 = ps[i];
            long long int s2 = ps[n] - s1;
            if (__gcd(s1, s2) > max)
                max = __gcd(s1, s2);
        }
        cout << max << endl;
    }

    return 0;
}
