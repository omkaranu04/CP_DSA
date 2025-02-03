#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int n, k;
vector<ll> a, b, c;
set<tuple<ll, ll, ll>> s;
priority_queue<pair<ll, tuple<ll, ll, ll>>> pq;
ll cal(ll i, ll j, ll k)
{
    return a[i] * b[j] + b[j] * c[k] + c[k] * a[i];
}
void add(ll i, ll j, ll k)
{
    if (i < n && j < n && k < n && s.find(make_tuple(i, j, k)) == s.end())
    {
        s.insert(make_tuple(i, j, k));
        pq.push(make_pair(cal(i, j, k), make_tuple(i, j, k)));
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        cin >> b[i];
    for (ll i = 0; i < n; i++)
        cin >> c[i];

    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    sort(c.begin(), c.end(), greater<ll>());

    add(0, 0, 0);
    for (int i = 0; i < k; i++)
    {
        auto heap_top = pq.top();
        pq.pop();
        if (i == k - 1)
            cout << heap_top.first << endl;
        auto x = heap_top.second;
        ll ii = get<0>(x);
        ll jj = get<1>(x);
        ll kk = get<2>(x);
        add(ii + 1, jj, kk);
        add(ii, jj + 1, kk);
        add(ii, jj, kk + 1);
    }

    return 0;
}