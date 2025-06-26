#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll bestSum(const vector<ll> &a)
{
    unordered_map<ll, ll> mp;
    for (ll x : a)
        mp[x]++;

    vector<pair<ll, ll>> v;
    v.reserve(mp.size());
    for (auto &p : mp)
        v.push_back(p);
    sort(v.begin(), v.end());

    int k = (int)v.size();
    vector<ll> dp(k, 0);

    for (int i = 0; i < k; ++i)
    {
        ll val = v[i].first;
        ll gain = val * v[i].second;

        ll take = gain;
        if (i > 0 && val == v[i - 1].first + 1)
            take += (i > 1 ? dp[i - 2] : 0);
        else
            take += (i > 0 ? dp[i - 1] : 0);

        ll skip = (i > 0 ? dp[i - 1] : 0);

        dp[i] = max(take, skip);
    }
    return dp.back();
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;

    cout << bestSum(a) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    while (T--)
        solve();
    return 0;
}
