#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; // number of test cases
    if (!(cin >> T))
        return 0;

    const int MAX_BITS = 17; // buckets 0 … 16
    while (T--)
    {
        int n;
        cin >> n;
        vector<int64> a(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> a[i];

        /* quick impossibility checks */
        if (n == 2 && a[1] != a[2])
        { // only one split possible
            cout << -1 << '\n';
            continue;
        }
        if ((accumulate(a.begin() + 1, a.end(), 0LL) & 1LL) == 1)
        { // odd total
            cout << -1 << '\n';
            continue;
        }

        cout << MAX_BITS << '\n'; // we will always output 17 rounds
        for (int k = 0; k < MAX_BITS; ++k)
        {
            int pivot = (1 << k); // split after all “smaller” indices
            vector<int64> b(n + 1, 0);

            for (int i = 1; i <= n; ++i)
            {
                int highest = 31 - __builtin_clz(i); // highest set bit of i
                if (highest < k)
                    b[i] = a[i]; // left side
                else if (highest == k)
                    b[i] = a[i]; // right side
            }

            /* subtract and print */
            for (int i = 1; i <= n; ++i)
                a[i] -= b[i];
            for (int i = 1; i <= n; ++i)
                cout << b[i] << (i == n ? '\n' : ' ');
        }
    }
    return 0;
}