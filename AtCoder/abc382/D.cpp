#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void generate(int n, int m, int pos, vector<vector<ll>> &ans, vector<ll> &temp, int level)
{
    if (temp.size() == n)
    {
        ans.push_back(temp);
        return;
    }

    for (ll i = pos + 10; i <= m - (level - 1) * 10; i++)
    {
        temp.push_back(i);
        generate(n, m, i, ans, temp, level - 1);
        temp.pop_back();
    }
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> ans;
    vector<ll> temp;
    ll level = n;
    for (int i = 1; i <= m - (level - 1) * 10; i++)
    {
        temp.push_back(i);
        generate(n, m, i, ans, temp, level - 1);
        temp.pop_back();
    }
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
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