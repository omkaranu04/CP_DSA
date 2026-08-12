#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> b(n);
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
        mp[b[i]]++;
    }
    if (mp.size() == 1)
    {
        ll ans = 0;
        for (auto x : mp)
        {
            ans += (x.second * (x.second - 1)) / 2;
        }
        cout << 0 << " " << ans << endl;
    }
    else
    {
        ll mini = *min_element(b.begin(), b.end());
        ll maxi = *max_element(b.begin(), b.end());
        ll ans = mp[mini] * mp[maxi];
        cout << (maxi - mini) << " " << ans << endl;
    }
    return 0;
}