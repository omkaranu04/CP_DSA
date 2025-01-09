#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
vector<ll> p;
int main(ll argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    p.resize(n);
    for (ll i = 0; i < n; i++)
        cin >> p[i];
    sort(p.begin(), p.end());
    ll median = p[n / 2];
    ll ans = 0;
    for (ll i = 0; i < n; i++)
        ans += abs(p[i] - median);
    if (n % 2 == 0)
    {
        ll median2 = p[n / 2 - 1];
        ll ans2 = 0;
        for (ll i = 0; i < n; i++)
            ans2 += abs(p[i] - median2);
        ans = min(ans, ans2);
    }
    cout << ans << endl;
    return 0;
}