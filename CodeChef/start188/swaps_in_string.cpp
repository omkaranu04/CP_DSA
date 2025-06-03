#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> a(n + 1, 0), c(n + 2, 0);
    for (ll i = 1; i <= n; i++)
    {
        if (s[i - 1] == 'A')
            a[i] = a[i - 1] + 1;
        else if (s[i - 1] == 'B')
            a[i] = a[i - 1];
        else
            a[i] = 0;
    }
    for (ll i = n; i >= 1; i--)
    {
        if (s[i - 1] == 'C')
            c[i] = c[i + 1] + 1;
        else if (s[i - 1] == 'B')
            c[i] = c[i + 1];
        else
            c[i] = 0;
    }
    ll ans = 0, i = 1;
    while (i <= n)
    {
        if (s[i - 1] != 'B')
        {
            i++;
            continue;
        }
        ll j = i;
        while (j <= n && s[j - 1] == 'B')
            j++;
        ll len = j - i;
        ans += len * max(a[i - 1], c[j]);
        i = j;
    }
    cout << ans << endl;
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