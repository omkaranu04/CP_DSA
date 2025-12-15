#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    string s;
    cin >> s;
    ll n = s.length();
    vector<ll> ans(n, 0);
    for (ll i = 0; i < n;)
    {
        if (s[i] == 'R')
        {
            ll fR = i;
            while (s[i] == 'R')
                i++;
            ll lR = i - 1;
            ll fL = i;
            while (i < n && s[i] == 'L')
                i++;
            ll lL = i - 1;
            ll rlen = lR - fR + 1;
            ll llen = lL - fL + 1;
            ans[lR] += (rlen + 1) / 2 + llen / 2;
            ans[fL] += rlen / 2 + (llen + 1) / 2;
        }
    }
    for (auto x : ans)
        cout << x;
    cout << endl;
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