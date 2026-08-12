#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if (s.length() % 2 == 0)
    {
        vector<ll> even(26, 0), odd(26, 0);
        for (ll i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                even[s[i] - 'a']++;
            else
                odd[s[i] - 'a']++;
        }
        ll maxeven = LLONG_MIN, maxodd = LLONG_MIN;
        for (ll i = 0; i < 26; i++)
        {
            maxeven = max(maxeven, even[i]);
            maxodd = max(maxodd, odd[i]);
        }
        cout << n - maxeven - maxodd << endl;
    }
    else
    {
        vector<ll> lefteven(26, 0), leftodd(26, 0), righteven(26, 0), rightodd(26, 0);
        ll ans = LLONG_MAX;
        for (ll i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                righteven[s[i] - 'a']++;
            else
                rightodd[s[i] - 'a']++;
        }
        for (ll i = 0; i < n; i++)
        {
            // remove
            if (i % 2 == 0)
                righteven[s[i] - 'a']--;
            else
                rightodd[s[i] - 'a']--;

            // calculate
            ll maxeven = LLONG_MIN, maxodd = LLONG_MIN;
            for (ll j = 0; j < 26; j++)
            {
                maxeven = max(maxeven, lefteven[j] + rightodd[j]);
                maxodd = max(maxodd, leftodd[j] + righteven[j]);
            }
            ans = min(ans, 1 + n - 1 - maxeven - maxodd);

            // add
            if (i % 2 == 0)
                lefteven[s[i] - 'a']++;
            else
                leftodd[s[i] - 'a']++;
        }
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