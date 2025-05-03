#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    for(int i=1;i<=n+1;i++)
    {
        if(mp[i]<=2) continue;
        mp[i+1] += (mp[i] - 2);
        mp[i] = 2;
    }
    bool flag = false;
    for(int i=1;i<=n;i++)
    {
        if(mp[i]%2 == 1) flag = true;
    }
    if(!flag) cout<<"Yes\n";
    else cout<<"No\n";
    return;
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