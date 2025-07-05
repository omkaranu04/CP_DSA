#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    map<char, ll> mp;
    for (auto c : s)
        mp[c]++;
    ll cnt = 0;
    for (auto x : mp)
        if (x.second % 2)
            cnt++;
    if (cnt > 1)
    {
        cout << -1 << endl;
        return;
    }
    ll l = 0, r = n - 1;
    ll ans = 0;
    while (l < r)
    {
        if (s[l] == s[r])
        {
            l++;
            r--;
        }
        else
        {
            ll k = r;
            while (k > l && s[k] != s[l])
                k--;
            if (k == l)
            {
                swap(s[k], s[k + 1]);
                ans++;
            }
            else
            {
                for (ll i = k; i < r; i++)
                {
                    swap(s[i], s[i + 1]);
                    ans++;
                }
                l++;
                r--;
            }
        }
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