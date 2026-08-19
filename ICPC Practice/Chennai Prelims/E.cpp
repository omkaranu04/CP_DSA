#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 998244353;
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> s(n);
    for(int i = 0 ; i < n; i++)
        cin >> s[i];
    sort(s.begin(), s.end());
    ll cnt = 0;
    for(int i = n-1; i >= 0; i--){
        ll num = s[i];
        ll inc = num - i + 1;
        ll need = (n - i - 1);
        if (need > k)
            break;
        cnt += min(inc, k - need + 1);
        cnt %= MOD;
        cout << "ok" << cnt << endl;
    }
    ll mx = 0;
    for(int i = n-1; i >= 0; i--){
        ll num = s[i];
        ll need = (n - i - 1) + (num + 1 - (i+1));
        if (need > k)
            continue;
        mx = max(mx, k - need);
    }
    ll num = 0;
    ll need = n;
    if (need <= k)
        mx = max(mx, k - need);
    cnt += mx;
    cnt %= MOD;
    cout << cnt << endl;
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