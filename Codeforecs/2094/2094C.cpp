#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> g(n + 1, vector<ll>(n + 1));
    vector<ll> p(2 * n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> g[i][j];
            p[i + j] = g[i][j];
        }
    }
    ll sum = 0;
    for (int i = 1; i <= 2 * n; i++)
        sum += p[i];
    ll xsum = 2 * n * (2 * n + 1) / 2 - sum;
    p[1] = xsum;
    for (int i = 1; i <= 2 * n; i++)
        cout << p[i] << " ";
    cout << "\n";
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