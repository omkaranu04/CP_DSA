#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll k;
    cin >> k;
    vector<ll> a(k);
    unordered_map<ll, ll> mp;
    for (ll i = 0; i < k; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    ll n = -1, m = -1;
    for (ll i = 0; i < k; i++)
    {
        if ((k - 2) % a[i] == 0)
        {
            ll temp = (k - 2) / a[i];
            if (temp == a[i])
            {
                if (mp[temp] > 1)
                {
                    n = a[i];
                    m = temp;
                    break;
                }
            }
            else if (mp[temp] > 0)
            {
                n = a[i];
                m = temp;
                break;
            }
        }
    }
    cout << n << " " << m << endl;
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