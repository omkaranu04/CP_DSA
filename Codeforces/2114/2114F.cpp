#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<pair<ll, ll>> factor(ll n)
{
    vector<pair<ll, ll>> f;
    for (ll p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        {
            ll cnt = 0;
            while (n % p == 0)
            {
                n /= p;
                ++cnt;
            }
            f.emplace_back(p, cnt);
        }
    }
    if (n > 1)
        f.emplace_back(n, 1);
    return f;
}

void gen_divs(ll i, ll cur,
              const vector<pair<ll, ll>> &fac,
              vector<ll> &divs)
{
    if (i == (ll)fac.size())
    {
        divs.push_back(cur);
        return;
    }
    auto [p, e] = fac[i];
    for (ll exp = 0; exp <= e; ++exp)
    {
        gen_divs(i + 1, cur, fac, divs);
        cur *= p;
    }
}

ll steps_to_one(ll T, ll k)
{
    if (T == 1)
        return 0;
    auto fac = factor(T);
    vector<ll> D;
    gen_divs(0, 1, fac, D);
    unordered_map<ll, ll> dist;
    queue<ll> q;
    dist[T] = 0;
    q.push(T);
    while (!q.empty())
    {
        ll cur = q.front();
        q.pop();
        ll d_cur = dist[cur];
        if (cur <= k)
            return d_cur + 1;
        for (ll d : D)
        {
            if (d <= 1 || d > k)
                continue;
            if (cur % d)
                continue;
            ll nxt = cur / d;
            if (!dist.count(nxt))
            {
                dist[nxt] = d_cur + 1;
                if (nxt == 1)
                    return dist[nxt];
                q.push(nxt);
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T;
    cin >> T;
    while (T--)
    {
        ll x, y;
        ll k;
        cin >> x >> y >> k;
        if (x == y)
        {
            cout << 0 << "\n";
            continue;
        }
        if (k == 1)
        {
            cout << -1 << "\n";
            continue;
        }
        ll g = gcd(x, y);
        ll dx = x / g, dy = y / g;
        ll a = steps_to_one(dx, k);
        ll b = steps_to_one(dy, k);
        if (a < 0 || b < 0)
            cout << -1 << "\n";
        else
            cout << (a + b) << "\n";
    }
    return 0;
}