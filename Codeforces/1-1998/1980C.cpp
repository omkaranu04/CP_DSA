#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> b[i];
        }

        int m;
        cin >> m;
        vector<int> d(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> d[i];
        }

        vector<int> f;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] != b[i])
            {
                f.push_back(b[i]);
            }
        }

        if (f.size() > d.size())
        {
            cout << "NO\n";
            continue;
        }

        if (f.empty())
        {
            if (count(b.begin(), b.end(), d[m - 1]) == 0)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
            }
            continue;
        }

        if (count(b.begin(), b.end(), d[m - 1]) == 0)
        {
            cout << "NO\n";
            continue;
        }

        sort(d.begin(), d.end());
        sort(f.begin(), f.end());

        int i = 0, j = 0;
        while (i < f.size() && j < d.size())
        {
            if (f[i] == d[j])
            {
                ++i;
            }
            ++j;
        }

        if (i == f.size())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
