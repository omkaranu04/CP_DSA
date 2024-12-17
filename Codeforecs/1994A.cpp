#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n][m + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    if (n == 1 && m == 1)
    {
        cout << -1 << endl;
        return;
    }
    else if (m > 1 && n > 1)
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i][m] << " ";
            for (int j = 1; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    else if (m == 1)
    {
        cout << a[n - 1][1] << endl;
        for (int i = 0; i < n - 1; i++)
        {
            cout << a[i][1] << endl;
        }
        return;
    }
    else if (n == 1)
    {
        cout << a[0][m] << " ";
        for (int i = 1; i < m; i++)
        {
            cout << a[0][i] << " ";
        }
        cout << endl;
        return;
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}