#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, m;
    cin >> n >> m;
    if (m >= 2 * n)
    {
        cout << "NO\n";
        return;
    }
    int colour[2 * n][m];
    cout << "YES\n";
    for (int i = 0; i < m; i++)
    {
        colour[0][i] = 1;
    }
    for (ll i = 1; i < n; ++i)
    {
        for (int j = 0; j < m; j++)
        {
            if (i > j)
                colour[i][j] = colour[i - 1][j];
            else if (i == j)
                colour[i][j] = i + 1;
            else
                colour[i][j] = colour[i][j - 1];
        }
    }
    for (int i = n; i < 2 * n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            colour[i][j] = j + 1;
        }
    }

    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << colour[i][j] << " ";
        }
        cout << endl;
    }
    return;
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