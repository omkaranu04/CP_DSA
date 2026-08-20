#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll n;
ll dx[6] = {-1, -1, 0, 0, 1, 1};
ll dy[6] = {-1, 0, -1, 1, 0, 1};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    set<pair<ll, ll>> blacks;
    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        blacks.insert({x, y});
    }

    map<pair<ll, ll>, ll> visited;
    ll ans = 0;
    for (auto start : blacks)
    {
        if (visited.find(start) != visited.end())
            continue;
        ans++;

        queue<pair<ll, ll>> q;
        q.push(start);
        visited[start] = 1;

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for (ll i = 0; i < 6; i++)
            {
                ll nx = x + dx[i], ny = y + dy[i];
                if (blacks.count({nx, ny}) && visited.find({nx, ny}) == visited.end())
                {
                    visited[{nx, ny}] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}