#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
void solve()
{
    ll n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    ll ans = 0;
    for (ll i = 0; i < n / 2; i++)
    {
        if (s[i] == s[n - i - 1])
            continue;
        if (s[i] == c || s[n - i - 1] == c)
            ans += 1;
        else
            ans += 2;
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