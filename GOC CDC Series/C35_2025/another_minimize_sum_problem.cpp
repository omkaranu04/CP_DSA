#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll n, k;
    cin >> n >> k;
    priority_queue<ll> pq;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        pq.push(x);
    }
    while (k--)
    {
        ll currmax = pq.top();
        pq.pop();
        currmax = (currmax + 1) / 2;
        pq.push(currmax);
    }
    ll ans = 0;
    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
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