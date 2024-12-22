#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> r(n), plush(n, 1);
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
        r[i]--;
    }
    vector<bool> visited(n, false);
    vector<ll> dist(n, 0);
    ll ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<ll> path;
            ll curr = i;

            while (!visited[i])
            {
                visited[curr] = true;
                path.push_back(curr);
                curr = r[curr];
            }
            ll start = find(path.begin(), path.end(), curr) - path.begin();
            ll leng = path.size() - start;

            for (int j = start; j < path.size(); j++)
            {
                dist[path[j]] = 0;
            }
            for (int j = start - 1; j >= 0; j--)
            {
                dist[path[j]] = dist[path[j + 1]] + 1;
            }

            ans = lcm(ans, leng);
        }
    }
    cout << ans << "\n";
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