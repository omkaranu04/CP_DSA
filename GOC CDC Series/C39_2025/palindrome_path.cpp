#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    vector<vector<pair<ll, ll>>> g(n + 1);
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<ll> mask(n + 1, 0), par(n + 1, 0);
    stack<ll> st;
    st.push(1);
    par[1] = 0;
    mask[1] = 0;
    map<ll, ll> freq;
    ll ans = 0;
    while (!st.empty())
    {
        ll u = st.top();
        st.pop();

        ll m = mask[u];
        auto it = freq.find(m);
        if (it != freq.end())
            ans += it->second;

        for (ll k = 0; k < 26; k++)
        {
            ll nm = m ^ (1LL << k);
            it = freq.find(nm);
            if (it != freq.end())
                ans += it->second;
        }

        freq[m]++;

        for (auto x : g[u])
        {
            ll v = x.first, w = x.second;
            if (v == par[u])
                continue;
            par[v] = u;
            mask[v] = m ^ (1 << (w - 1));
            st.push(v);
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