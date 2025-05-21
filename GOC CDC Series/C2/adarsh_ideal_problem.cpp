#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
vector<ll> factors(ll n)
{
    vector<ll> tmp;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            tmp.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        tmp.push_back(n);
    return tmp;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<ll>> allFactors(n);
    for (ll i = 0; i < n; i++)
        allFactors[i] = factors(a[i]);

    ll ans = 1, i = 0, j = 0;
    map<ll, ll> mp;

    while (i < n)
    {
        bool okay = true;
        for (auto x : allFactors[i])
        {
            mp[x]++;
            if (mp[x] > 1)
                okay = false;
        }

        while (!okay)
        {
            for (auto x : allFactors[j])
            {
                mp[x]--;
                if (mp[x] == 0)
                    mp.erase(x);
            }
            j++;

            okay = true;
            for (auto &x : mp)
            {
                if (x.second > 1)
                {
                    okay = false;
                    break;
                }
            }
        }

        ans = max(ans, i - j + 1);
        i++;
    }
    cout << ans << endl;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();
}