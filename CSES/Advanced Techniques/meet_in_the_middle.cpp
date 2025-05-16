#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void def(vector<ll> &a, vector<ll> &mp)
{
    ll n = a.size();
    for (ll mask = 0; mask < (1LL << n); mask++)
    {
        ll sum = 0;
        for (ll i = 0; i < n; i++)
            if (mask & (1LL << i))
                sum += a[i];
        mp.push_back(sum);
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, x;
    cin >> n >> x;
    vector<ll> t(n), t1, t2;
    for (ll i = 0; i < n; i++)
    {
        cin >> t[i];
        if (i % 2)
            t1.push_back(t[i]);
        else
            t2.push_back(t[i]);
    }
    vector<ll> mp1, mp2;
    def(t1, mp1);
    def(t2, mp2);
    sort(mp2.begin(), mp2.end());
    ll ans = 0;
    for (auto it : mp1)
    {
        auto it1 = lower_bound(mp2.begin(), mp2.end(), x - it);
        auto it2 = upper_bound(mp2.begin(), mp2.end(), x - it);
        ans += (it2 - it1);
    }
    cout << ans << endl;
    return 0;
}