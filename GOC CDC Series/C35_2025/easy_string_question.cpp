#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    string s, t;
    cin >> s;
    cin >> t;
    ll l1 = s.length(), l2 = t.length();
    if (s + t != t + s)
        cout << -1 << endl;
    else
    {
        ll len = (l1 * l2) / __gcd(l1, l2);
        string ans = "";
        for (ll i = 0; i < len / l1; i++)
            ans += s;
        cout << ans << endl;
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