#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void generate_permutations(map<ll, ll> &mp, ll level, ll n, vector<ll> &tmp)
{
    if (level == n)
    {
        for (auto x : tmp)
        {
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    for (auto x : mp)
    {
        if (x.second > 0)
        {
            tmp.push_back(x.first);
            mp[x.first]--;
            generate_permutations(mp, level + 1, n, tmp);
            mp[x.first]++;
            tmp.pop_back();
        }
    }
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (ll i = 0; i < n; i++)
    {
        mp[a[i]]++;
    }
    vector<ll> tmp;
    generate_permutations(mp, 0, n, tmp);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}