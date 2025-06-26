#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
struct job
{
    ll start, end;
    ll cost;
};
bool comp(const job &j1, const job &j2)
{
    if (j1.end == j2.end)
        return j1.cost > j2.cost;
    return j1.end < j2.end;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<job> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i].start >> a[i].end >> a[i].cost;
    sort(a.begin(), a.end(), comp);
    vector<ll> ends(n + 1, 0), dp(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        ends[i] = a[i - 1].end;
    for (ll i = 1; i <= n; i++)
    {
        ll idx = upper_bound(ends.begin() + 1, ends.begin() + i, a[i - 1].start - 1) - ends.begin() - 1;
        ll take = dp[idx] + a[i - 1].cost;
        ll nottake = dp[i - 1];
        dp[i] = max(take, nottake);
    }
    cout << dp[n];
    return 0;
}