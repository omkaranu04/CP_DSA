#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i < n + 1; i++)
        cin >> a[i];
    vector<ll> dist(n + 1, 1e9);
    dist[1] = 0;
    set<ll> unvis;
    for (ll i = 2; i <= n; i++)
        unvis.insert(i);
    deque<ll> q;
    q.push_back(1);
    while (!q.empty())
    {
        ll i = q.front();
        q.pop_front();
        ll reach = i + a[i];
        auto it = unvis.upper_bound(i);
        while (it != unvis.end() && *it <= reach)
        {
            ll j = *it;
            dist[j] = dist[i] + 1;
            q.push_back(j);
            it = unvis.erase(it);
        }
    }
    ll qu;
    cin >> qu;
    while (qu--)
    {
        ll x;
        cin >> x;
        cout << (dist[x] < 1e9 ? dist[x] : -1) << endl;
    }
}