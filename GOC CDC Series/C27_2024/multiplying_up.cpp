#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repi(i, a, n) for (ll i = a; i < n; i++)
#define repii(i, a, n, b) for (ll i = a; i < n; i += b)
#define mod 1000000007
#define pb push_back

vector<vector<ll>> v;
vector<ll> cp;
ll ans = 0;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;

    if (a == 0)
        return b;

    if (a > b)
        return gcd(b, a % b);

    return gcd(a, b % a);
}

ll maxi(ll a, ll b)
{
    if (a > b)
        return a;

    else
        return b;
}

ll mini(ll a, ll b)
{
    if (a > b)
        return b;

    else
        return a;
}

int modpower(ll a, ll b, ll c)
{
    ll r = 1;

    a = a % c;

    while (b > 0)
    {
        if (b % 2 == 1)
            r = (r * a) % c;

        b = b / 2;
        a = (a * a) % c;
    }

    return r;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n, k, m;
        cin >> n >> k >> m;

        ll a[n], vmax = 0;

        rep(i, n) cin >> a[i], vmax = maxi(vmax, a[i]);
        if (k == 1)
        {
            rep(i, n) cout << a[i] << " ";
            cout << "\n";
            continue;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        rep(i, n) pq.push({a[i], i});
        while (true)
        {
            pair<int, int> p;
            p = pq.top();

            if (m > 0 && p.first * k <= vmax)
            {
                pq.pop();
                p.first *= k;
                pq.push(p);
                m--;
            }
            else
                break;
        }

        vector<pair<int, int>> v;

        rep(i, n)
            v.pb(pq.top()),
            pq.pop();

        ll q = m / n, r = m % n;
        ll fom = modpower(k, q, mod);

        rep(i, n)
        {
            v[i].first = v[i].first % mod;
            v[i].first = (v[i].first * fom) % mod;
        }
        rep(i, r)
        {
            v[i].first = v[i].first % mod;
            v[i].first = (v[i].first * k) % mod;
        }
        rep(i, n)
        {
            a[v[i].second] = v[i].first;
        }
        rep(i, n)
                cout
            << a[i] << " ";
        cout << "\n";
    }
}