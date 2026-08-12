#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<vector<string>> b(m, vector<string>(n));
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> b[i][j];
    vector<bool> exists(n, false);
    ll maxmatch = 0;
    for (int i = 0; i < m; i++)
    {
        ll temp = 0;
        for (int j = 0; j < n; j++)
        {
            if (b[i][j] == a[j])
            {
                exists[j] = true;
                temp++;
            }
        }
        maxmatch = max(maxmatch, temp);
    }
    bool all = exists[0];
    for (int i = 1; i < n; i++)
        all &= exists[i];
    if (!all)
        cout << -1 << endl;
    else
        cout << n + 2 * (n - maxmatch) << endl;
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