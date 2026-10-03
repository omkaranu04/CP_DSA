#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 998244353;
const ll MAXN = 200010;
ll modpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll t = modpow(a, b / 2);
    t = (t * t) % MOD;
    if (b % 2 == 0)
        return t;
    return (t * a) % MOD;
}

vector<ll> fact(MAXN + 1), ifact(MAXN + 1);
ll nCr(ll n, ll r)
{
    if (r > n || r < 0)
        return 0;
    return ((fact[n] * ifact[r]) % MOD * ifact[n - r]) % MOD;
}

struct SegTree
{
    ll n;
    vector<ll> st;
    SegTree(const ll _n)
    {
        n = _n;
        st.resize(4 * n + 10, 0);
    }
    void update(ll n, ll l, ll r, ll pos, ll val)
    {
        if (l == r)
        {
            st[n] += val;
            return;
        }
        ll m = (l + r) / 2;
        if (pos <= m)
            update(2 * n, l, m, pos, val);
        else
            update(2 * n + 1, m + 1, r, pos, val);
        st[n] = st[2 * n] + st[2 * n + 1];
    }
    void update(ll pos, ll val)
    {
        update(1, 0, n - 1, pos, val);
    }
    ll query(ll n, ll l, ll r, ll ql, ll qr)
    {
        if (r < ql || l > qr)
            return 0;
        if (l >= ql && r <= qr)
            return st[n];
        ll m = (l + r) / 2;
        return query(2 * n, l, m, ql, qr) + query(2 * n + 1, m + 1, r, ql, qr);
    }
    ll query(ll l, ll r)
    {
        return query(1, 0, n - 1, l, r);
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T;
    cin >> T;

    // cout << "I am here\n";
    fact[0] = 1;
    for (ll i = 1; i <= MAXN; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    ifact[MAXN] = modpow(fact[MAXN], MOD - 2);
    for (ll i = MAXN; i >= 1; i--)
        ifact[i - 1] = (ifact[i] * i) % MOD;
    // cout << "I am here\n";

    while (T--)
    {
        // cout << "I am here\n";
        ll n;
        cin >> n;
        vector<ll> p(n);
        for (auto &x : p)
            cin >> x;
        SegTree segtree(n + 10);
        vector<ll> biggie(n);
        for (ll i = 0; i < n; i++)
        {
            ll q = segtree.query(p[i], n);
            biggie[i] = q;
            segtree.update(p[i], 1);
        }
        // for (auto x : biggie)
        //     cout << x << " ";
        // cout << endl;
        vector<ll> ps(n, 0);
        for (ll i = 0; i < n; i++)
            if (biggie[i])
                ps[i] = 1;
        for (ll i = n - 2; i >= 0; i--)
            ps[i] = ps[i + 1] + ps[i];
        // for (auto x : ps)
        //     cout << x << " ";
        // cout << endl;
        sort(biggie.begin(), biggie.end());

        vector<ll> mp(n + 5, 0);
        for (auto x : biggie)
            mp[x]++;
        ll prev = 0, ans = 1;
        for (ll i = n; i >= 1; i--)
        {
            if (mp[i] == 0)
                continue;
            ll t1 = ps[i] - prev;
            ans = (ans * nCr(t1, mp[i])) % MOD;
            prev += mp[i];
        }
        cout << ans % MOD << endl;
    }
    return 0;
}