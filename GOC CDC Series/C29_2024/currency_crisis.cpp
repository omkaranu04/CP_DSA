#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    ll ga, sa, pa, gb, sb, pb;
    cin >> ga >> sa >> pa >> gb >> sb >> pb;
    vector<ll> dp1(n+1, 0);
    for(ll i=1;i<=n;i++)
    {
        ll p = 0;
        if(i>=ga) p = max(p, dp1[i-ga] + (gb-ga));
        if(i>=sa) p = max(p, dp1[i-sa] + (sb-sa));
        if(i>=pa) p = max(p, dp1[i-pa] + (pb-pa));
        dp1[i] = max(dp1[i-1], p);
    }
    n += dp1[n];
    vector<ll> dp2(n+1, 0);
    for(ll i=1;i<=n;i++)
    {
        ll p = 0;
        if(i>=gb) p = max(p, dp2[i-gb] + (ga-gb));
        if(i>=sb) p = max(p, dp2[i-sb] + (sa-sb));
        if(i>=pb) p = max(p, dp2[i-pb] + (pa-pb));
        dp2[i] = max(dp2[i-1], p);
    }
    cout<<dp1.back()+dp2.back();
    return 0;
}   