#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(2 * n);
    for (int i = 0; i < 2 * n; i++)
        cin >> arr[i];
    vector<vector<ll>> pos(n + 1);
    for (int i = 0; i < 2 * n; i++)
        pos[arr[i]].push_back(i);
    set<pair<ll, ll>> ans;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        ll a = arr[i], b = arr[i + 1];
        if (pos[a][0] + 1 == pos[a][1])
            continue;
        if (pos[b][0] + 1 == pos[b][1])
            continue;
        vector<ll> temp;
        temp.push_back(pos[a][0]);
        temp.push_back(pos[a][1]);
        temp.push_back(pos[b][0]);
        temp.push_back(pos[b][1]);
        sort(temp.begin(), temp.end());
        if (temp[0] + 1 == temp[1] && temp[2] + 1 == temp[3])
            ans.insert(minmax(a, b));
    }
    cout << ans.size() << "\n";
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