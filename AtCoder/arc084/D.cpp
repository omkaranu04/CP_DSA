#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll K;
    cin >> K;
    vector<ll> dist(K + 1, 1e18);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (ll d = 1; d <= 9; d++)
    {
        ll r = d % K;
        if (dist[r] > d)
        {
            dist[r] = d;
            pq.push({d, r});
        }
    }
    while (!pq.empty())
    {
        auto [d, r] = pq.top();
        pq.pop();
        if (d != dist[r])
            continue;
        if (r == 0)
        {
            cout << d;
            return 0;
        }
        for (ll i = 0; i <= 9; i++)
        {
            ll nr = (r * 10 + i) % K;
            ll nd = d + i;
            if (dist[nr] > nd)
            {
                dist[nr] = nd;
                pq.push({nd, nr});
            }
        }
    }
    return 0;
}