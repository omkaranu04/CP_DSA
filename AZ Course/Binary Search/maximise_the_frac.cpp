#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        cin >> b[i];
    ld lo = 0.0, hi = 1e9, ans = 0.0;
    while (abs(lo - hi) > 1e-9)
    {
        ld mid = (lo + hi) / 2.0;
        priority_queue<ld, vector<ld>, greater<ld>> pq;
        for (ll i = 0; i < n; i++)
        {
            pq.push(a[i] - mid * b[i]);
            if (pq.size() > k)
                pq.pop();
        }
        ld ss = 0.0;
        while (pq.size())
        {
            ss += pq.top();
            pq.pop();
        }
        if (ss >= 0.0)
        {
            ans = mid;
            lo = mid;
        }
        else
            hi = mid;
    }
    cout << fixed << setprecision(6) << ans << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}