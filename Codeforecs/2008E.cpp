#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll max(ll a, ll b)
{
    return a > b ? a : b;
}
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = n;
    if (!(n % 2))
    {
        vector<ll> a[2] = {vector<ll>(26, 0), vector<ll>(26, 0)};
        for (int i = 0; i < n; i++)
        {
            a[i % 2][s[i] - 'a']++;
        }
        for (int i = 0; i < 2; i++)
        {
            ll maxi = INT_MIN;
            for (int j = 0; j < 26; j++)
            {
                maxi = max(maxi, a[i][j]);
            }
            ans -= maxi;
        }
        cout << ans << endl;
    }
    else
    {
        vector<int> prefix[2] = {vector<int>(26), vector<int>(26)};
        vector<int> suffix[2] = {vector<int>(26), vector<int>(26)};
        for (int i = 0; i < n; i++)
        {
            suffix[i % 2][s[i] - 'a']++;
        }
        for (int i = 0; i < n; i++)
        {
            suffix[i % 2][s[i] - 'a']--;
            ll temp = n;
            for (int k = 0; k < 2; k++)
            {
                ll maxi = 0;
                for (int j = 0; j < 26; j++)
                {
                    maxi = max(maxi, prefix[k][j] + suffix[1 - k][j]);
                }
                temp -= maxi;
            }
            ans = min(ans, temp);
            prefix[i % 2][s[i] - 'a']++;
        }
        cout << ans << endl;
    }
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