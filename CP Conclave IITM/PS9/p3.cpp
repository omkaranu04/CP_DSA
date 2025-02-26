#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        while (q--)
        {
            int k, x;
            cin >> k >> x;
            if (k == 1)
            {
                int count = lower_bound(a, a + n, x) - a;
                cout << count << endl;
            }
            else if (k == 2)
            {
                int count = upper_bound(a, a + n, x) - a;
                cout << count << endl;
            }
            else if (k == 3)
            {
                int count = upper_bound(a, a + n, x) - lower_bound(a, a + n, x);
                cout << count << endl;
            }
        }
    }

    return 0;
}
