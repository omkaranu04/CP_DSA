#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> k(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> k[i];
    }
    ll i = 0, j = 0, ans = 0;
    map<ll, ll> mp;
    for (j = 0; j < n; j++)
    {
        if (mp.find(k[j]) != mp.end() && mp[k[j]] >= i)
        {
            i = mp[k[j]] + 1;
        }
        mp[k[j]] = j;
        ans = max(ans, j - i + 1);
    }
    cout << ans << endl;
    return 0;
}