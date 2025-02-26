#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> stones(m);
    ll sum = 0;
    for (ll i = 0; i < m; i++)
    {
        cin >> stones[i].first;
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> stones[i].second;
        sum += stones[i].second;
    }
    if (sum < n || sum > n)
    {
        cout << -1 << endl;
        return 0;
    }
    sort(stones.begin(), stones.end());
    if (stones[0].first != 1)
    {
        cout << -1 << endl;
        return 0;
    }
    sum = 0;
    ll curr_sum = 0;
    for (int i = 0; i < m; i++)
    {
        if (curr_sum < stones[i].first - 1)
        {
            cout << -1 << endl;
            return 0;
        }
        curr_sum += stones[i].second;
        sum += stones[i].second * stones[i].first;
    }
    ll ans = (n * (n + 1)) / 2 - sum;
    cout << ans << endl;
    return 0;
}