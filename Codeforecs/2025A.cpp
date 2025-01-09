#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    string s, t;
    cin >> s;
    cin >> t;
    ll n = s.length();
    ll m = t.length();
    ll i = 0;
    ll lcp = 0;
    for (ll i = 0; i < min(n, m); ++i)
    {
        if (s[i] == t[i])
        {
            lcp++;
        }
        else
        {
            break;
        }
    }
    ll ans = (n - lcp) + (m - lcp) + lcp;
    if (lcp > 0)
        ans++;
    cout << ans << endl;
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