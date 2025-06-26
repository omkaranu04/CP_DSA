#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll n, m, x;
    cin >> n >> m >> x;
    ll q;
    vector<pair<ll, ll>> logs(m); // time, server_id
    for (ll i = 0; i < m; i++)
    {
        ll server_id, time;
        cin >> server_id >> time;
        server_id--;
        logs[i] = {time, server_id};
    }
    cin >> q;
    vector<pair<ll, ll>> queries(q); // time, idx;
    for (ll i = 0; i < q; i++)
    {
        cin >> queries[i].first;
        queries[i].second = i;
    }
    sort(logs.begin(), logs.end());
    sort(queries.begin(), queries.end());
    vector<ll> ans(q);
    vector<ll> cnt(n, 0);
    ll i = 0, j = 0, counter = 0;
    for (auto &[qr, idx] : queries)
    {
        ll l = qr - x, r = qr;
        while (j < m && logs[j].first <= r)
        {
            ll serv = logs[j].second;
            cnt[serv]++;
            if (cnt[serv] == 1)
                counter++;
            j++;
        }
        while (i < m && logs[i].first < l)
        {
            ll serv = logs[i].second;
            cnt[serv]--;
            if (cnt[serv] == 0)
                counter--;
            i++;
        }
        ans[idx] = n - counter;
    }
    for (auto x : ans)
        cout << x << endl;
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