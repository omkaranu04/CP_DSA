#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n, q;
vector<vector<char>> grid;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    grid.resize(n, vector<char>(n));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            cin >> grid[i][j];
    vector<vector<ll>> ps(n + 1, vector<ll>(n + 1, 0));
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            ll temp = (grid[i - 1][j - 1] == '*') ? 1 : 0;
            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + temp;
        }
    }
    // for (auto x : ps)
    // {
    //     for (auto y : x)
    //     {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
    while (q--)
    {
        ll y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        ll ans = ps[y2][x2] - ps[y1 - 1][x2] - ps[y2][x1 - 1] + ps[y1 - 1][x1 - 1];
        cout << ans << endl;
    }
    return 0;
}