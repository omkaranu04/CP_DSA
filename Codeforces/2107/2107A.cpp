#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a)
            cin >> x;

        int g = a[0];
        for (int i = 1; i < n; i++)
        {
            g = gcd(g, a[i]);
        }

        int splitIdx = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != g)
            {
                splitIdx = i;
                break;
            }
        }

        if (splitIdx < 0)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
            for (int i = 0; i < n; i++)
            {
                cout << (i == splitIdx ? 2 : 1) << ' ';
            }
            cout << "\n";
        }
    }

    return 0;
}