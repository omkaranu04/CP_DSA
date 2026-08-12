#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), x(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        x[i] = a[i];
    sort(x.begin(), x.end());
    if(x == a) cout<<"YES\n";
    else
    {
        for(int i=0;i<n-1;i++)
        {
            ll mini = min(a[i],a[i+1]);
            if(a[i+1])
        }
    }
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