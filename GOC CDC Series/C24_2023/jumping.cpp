#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
struct monotone_deque
{
    deque<pair<ll, ll>> dq;
    void push(ll idx, ll val)
    {
        while (!dq.empty() && dq.back().second > val)
            dq.pop_back();
        dq.push_back({idx, val});
    }
    void autopop(ll idx)
    {
        if (!dq.empty() && dq.front().first < idx)
            dq.pop_front();
    }
    ll getMin() { return dq.front().second; }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<ll> w(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> w[i];
    vector<ll> dp(n + 1, 0);
    monotone_deque dq;
    dq.push(0, dp[0]);
    for (ll i = 1; i <= n; i++)
    {
        dq.autopop(i - k);
        dp[i] = w[i] + dq.getMin();
        dq.push(i, dp[i]);
    }
    cout << dp[n];
    return 0;
}