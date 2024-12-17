#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> a(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    unordered_map<ll, pair<ll, ll>> mp;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            ll sum = a[i].first + a[j].first;

            if (mp.find(x - sum) != mp.end())
            {
                auto p = mp[x - sum];
                if (p.first != i && p.second != i && p.first != j && p.second != j)
                {
                    cout << a[i].second << " " << a[j].second << " " << a[p.first].second << " " << a[p.second].second << "\n";
                    return 0;
                }
            }
        }

        for (ll k = 0; k < i; k++)
        {
            ll sum = a[i].first + a[k].first;
            mp[sum] = {i, k};
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
