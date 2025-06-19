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

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        vector<pair<int, int>> operations;

        for (int i = 0; i < n; i++)
        {
            if (a[i] >= b[i])
            {
                operations.push_back({3, i + 1});
                swap(a[i], b[i]);
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (a[j] > a[j + 1])
                {
                    operations.push_back({1, j + 1});
                    swap(a[j], a[j + 1]);
                }
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (b[j] > b[j + 1])
                {
                    operations.push_back({2, j + 1});
                    swap(b[j], b[j + 1]);
                }
            }
        }

        cout << operations.size() << "\n";
        for (auto op : operations)
        {
            cout << op.first << " " << op.second << "\n";
        }
    }

    return 0;
}