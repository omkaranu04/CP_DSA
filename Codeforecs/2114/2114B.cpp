#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;

        int c0 = 0;
        for (char ch : s)
            if (ch == '0')
                ++c0;
        int c1 = n - c0;
        int m = n / 2;

        int mn = min(c0, c1);
        bool ok = true;

        if (k < m - mn || k > m)
            ok = false;
        else if (((c0 - m + k) & 1) != 0)
            ok = false;

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
