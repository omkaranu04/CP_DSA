#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        ll n = s.length();
        vector<ll> ps0(n + 1, 0), ps1(n + 1, 0);
        for (ll i = 0; i < n; i++)
        {
            ps0[i + 1] = ps0[i] + (s[i] == '0');
            ps1[i + 1] = ps1[i] + (s[i] == '1');
        }
        ll tot0 = ps0[n], tot1 = ps1[n];
        ll ans = LLONG_MAX;
        for (ll i = 0; i <= n; i++)
        {
            ll t1 = ps1[i] + (tot0 - ps0[i]);
            ll t2 = ps0[i] + (tot1 - ps1[i]);
            ans = min(ans, min(t1, t2));
        }
        cout << ans << endl;
    }
    return 0;
}