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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        if (n == 0)
        {
            cout << 0 << "\n";
            continue;
        }

        int count = 1;
        int last = a[0];

        for (int i = 1; i < n; i++)
        {
            if (a[i] >= last + 2)
            {
                count++;
                last = a[i];
            }
        }

        cout << count << "\n";
    }
    return 0;
}
