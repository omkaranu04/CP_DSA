#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

long long a[N];
int x[N], idx[N];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long s1 = 0, s2 = 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> x[i];
            idx[i] = i;
            s2 += x[i];
        }

        sort(idx + 1, idx + n + 1, [&](int i, int j)
             { return x[i] < x[j]; });

        for (int i = 1; i <= n; i++)
        {
            s2 -= x[idx[i]];
            s1 += x[idx[i]];
            a[idx[i]] = n + 1ll * x[idx[i]] * (2 * i - n) - s1 + s2;
        }

        for (int i = 1; i <= n; i++)
            cout << a[i] << " \n"[i == n];
    }
}
