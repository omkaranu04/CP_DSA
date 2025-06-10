#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll l = -1;
    for (ll i = 0; i + 1 < n; i++)
    {
        if (s[i] > s[i + 1])
        {
            l = i;
            break;
        }
    }
    if (l == -1)
    {
        cout << s << endl;
        return;
    }
    ll r = l;
    while (r + 1 < n && s[r + 1] <= s[l])
        r++;

    string ans = "";
    if (l > 0)
        ans.append(s, 0, l);
    ans.append(s, l + 1, r - l);
    ans.push_back(s[l]);
    if (r + 1 < n)
        ans.append(s, r + 1, n - (r + 1));
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