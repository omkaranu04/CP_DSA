#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> ans;
void solve()
{
    ll n, m, L;
    cin >> n >> m >> L;
    vector<tuple<ll, ll, ll>> all;
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        all.push_back({a, b, 1}); // hurdles
    }
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        all.push_back({a, b, 0}); // powerups
    }
    sort(all.begin(), all.end());
    ll power = 1;
    priority_queue<ll> pq;
    for (auto &[a, b, c] : all)
    {
        if (c == 0)
        {
            pq.push(b);
        }
        else
        {
            ll required_power = b - a + 2;
            while (!pq.empty() && required_power > power)
            {
                power += pq.top();
                pq.pop();
            }
            if (power < required_power)
            {
                ans.push_back(-1);
                return;
            }
        }
    }
    ans.push_back(m - pq.size());
    // cout << m - pq.size() << '\n';
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
    for (auto x : ans)
    {
        cout << x << '\n';
    }
    return 0;
}