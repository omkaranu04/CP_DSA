#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll val(ll k)
{
    ll m = 0;
    while ((m * (m - 1)) / 2 <= k)
        m++;
    return m - 1;
}
vector<pair<ll, ll>> helper(ll k, ll x, ll y)
{
    vector<pair<ll, ll>> temp;

    if (k == 0)
        return temp;

    ll m = val(k);
    for (int i = 0; i < m; i++)
        temp.push_back({x + i, y});
    ll rem_k = k - (m * (m - 1)) / 2;
    vector<pair<ll, ll>> temp1 = helper(rem_k, x + m, y + 1);

    for (auto i : temp1)
        temp.push_back(i);
    return temp;
}
void solve()
{
    ll k;
    cin >> k;
    vector<pair<ll, ll>> ans = helper(k, 0, 0);
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        cout << i.first << " " << i.second << endl;
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