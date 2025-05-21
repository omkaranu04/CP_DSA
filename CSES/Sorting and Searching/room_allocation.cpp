#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(3));
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    sort(a.begin(), a.end());
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> rooms;
    ll cnt = 0;
    vector<ll> ans(n);
    for (ll i = 0; i < n; i++)
    {
        ll arr = a[i][0], dept = a[i][1], idx = a[i][2];
        if (rooms.empty() || rooms.top().first >= arr)
        {
            cnt++;
            rooms.push({dept, cnt});
            ans[idx] = cnt;
        }
        else
        {
            ll vac = rooms.top().second;
            rooms.pop();
            rooms.push({dept, vac});
            ans[idx] = vac;
        }
    }
    cout << cnt << endl;
    for (auto x : ans)
        cout << x << " ";
    return 0;
}