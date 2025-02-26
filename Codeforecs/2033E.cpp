#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> p(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    vector<bool> visited(n + 1, false);
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (p[i] == 1)
        {
            visited[i] = true;
            continue;
        }
        if (p[p[i]] == i)
        {
            visited[i] = true;
            visited[p[i]] = true;
            continue;
        }
        if (!visited[i])
        {
            ll currlen = 0;
            while (!visited[i])
            {
                visited[i] = true;
                i = p[i];
                currlen++;
            }
            ans += (currlen - 1) / 2;
        }
    }
    cout << ans << endl;
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