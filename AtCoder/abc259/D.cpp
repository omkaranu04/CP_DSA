#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
const ll mod = 1e9 + 7;
struct DSU
{
    vector<ll> p, sz;
    DSU(ll n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
    ll find(ll a) { return p[a] == a ? a : p[a] = find(p[a]); }
    void merge(ll a, ll b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (sz[a] < sz[b])
            swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N;
    cin >> N;
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    vector<ll> x(N), y(N), r(N);
    for (ll i = 0; i < N; i++)
        cin >> x[i] >> y[i] >> r[i];
    DSU dsu(N);
    for (ll i = 0; i < N; i++)
    {
        for (ll j = i + 1; j < N; j++)
        {
            ll dx = x[i] - x[j], dy = y[i] - y[j];
            ll d2 = dx * dx + dy * dy;
            ll sum = r[i] + r[j];
            ll diff = llabs(r[i] - r[j]);
            if (diff * diff <= d2 && d2 <= sum * sum)
                dsu.merge(i, j);
        }
    }
    vector<ll> st, goal;
    for (ll i = 0; i < N; i++)
    {
        ll d2s = (x[i] - sx) * (x[i] - sx) + (y[i] - sy) * (y[i] - sy);
        if (d2s == r[i] * r[i])
            st.push_back(i);
        ll d2t = (x[i] - tx) * (x[i] - tx) + (y[i] - ty) * (y[i] - ty);
        if (d2t == r[i] * r[i])
            goal.push_back(i);
    }
    bool ok = false;
    for (auto u : st)
    {
        for (auto v : goal)
        {
            if (dsu.find(u) == dsu.find(v))
            {
                ok = true;
                break;
            }
        }
    }
    cout << (ok ? "Yes\n" : "No\n");
    return 0;
}