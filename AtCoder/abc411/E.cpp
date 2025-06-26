#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 998244353;
ll modpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = modpow(a, b / 2);
    res = (res * 1LL * res) % mod;
    if (b % 2)
        res = (res * 1LL * a) % mod;
    return res;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(6));
    vector<pair<ll, ll>> events;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < 6; j++)
        {
            cin >> a[i][j];
            events.push_back({a[i][j], i}); // val, id
        }
    }
    sort(events.begin(), events.end());

    ll inv6 = modpow(6, mod - 2);
    vector<ll> term(7, 0), invterm(7, 0);
    for (ll i = 1; i <= 6; i++)
    {
        term[i] = (i * 1LL * inv6) % mod;
        invterm[i] = modpow(term[i], mod - 2);
    }
    vector<ll> cnt(n, 0);
    ll select0 = n;
    ll ans = 0, prod = 1, fprev = 0;
    for (ll i = 0; i < events.size();)
    {
        ll val = events[i].first;
        while (i < events.size() && events[i].first == val)
        {
            ll dieno = events[i].second;
            ll ex = cnt[dieno];
            ll neeew = ex + 1;
            if (ex == 0)
                select0--;
            else
                prod = (prod * invterm[ex]) % mod;

            prod = (prod * term[neeew]) % mod;
            cnt[dieno] = neeew;
            i++;
        }
        ll f = (select0 > 0) ? 0 : prod;
        ll change = (f - fprev + mod) % mod;
        ans = (ans + (val % mod) * change) % mod;
        fprev = f;
    }
    cout << ans;
    return 0;
}