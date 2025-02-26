#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll const MAX = 2e7 + 10;
ll func[MAX];
ll f(ll a)
{
    while (a % 2 == 0)
        a /= 2;
    return a;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 1; i < MAX; i++)
    {
        func[i] = f(i);
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i; j < n; j++)
        {
            ll sum = a[i] + a[j];
            ans += func[sum];
        }
    }
    cout << ans << endl;
    return 0;
}