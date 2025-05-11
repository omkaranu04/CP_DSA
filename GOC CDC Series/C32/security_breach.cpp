#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
ll segTree[400100];
void build(ll idx, ll l, ll r, vector<ll> &D)
{
    if (l == r)
    {
        segTree[idx] = D[l];
        return;
    }
    ll m = (l + r) / 2;
    build(2 * idx, l, m, D);
    build(2 * idx + 1, m + 1, r, D);
    segTree[idx] = max(segTree[2 * idx], segTree[2 * idx + 1]);
}
ll query(ll idx, ll l, ll r, ll ql, ll T)
{
    if (r < ql || segTree[idx] <= T)
        return 0;
    if (l == r)
        return l;
    ll m = (l + r) / 2;
    ll res = query(2 * idx, l, m, ql, T);
    if (res)
        return res;
    return query(2 * idx + 1, m + 1, r, ql, T);
}
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> layers(n + 1), energy(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> layers[i];
    for (ll i = 1; i <= n; i++)
        cin >> energy[i];
    vector<ll> S(n + 1, 0), D(n + 1); // ps of layers
    for (ll i = 1; i <= n; i++)
        S[i] = S[i - 1] + layers[i];
    for (ll i = 1; i <= n; i++)
        D[i] = S[i] + energy[i];

    for (ll i = 0; i < 400100; i++)
        segTree[i] = -1e9;

    build(1, 1, n, D);
    vector<ll> ans(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        ll T = k + S[i - 1];
        ll t = query(1, 1, n, i, T);
        if (t == 0)
            t = n + 1;
        ans[i] = t - i;
    }
    for (ll i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}