#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, S;
vector<ll> a, b;
vector<vector<vector<ll>>> dp;
ll rec(ll idx, ll ft, ll st)
{
    if (idx == n)
        return (ft == S / 3 && st == S / 3) ? 0 : 1e9;

    if (dp[idx][ft][st] != -1)
        return dp[idx][ft][st];

    ll ans = 1e9;
    ll player = b[idx];
    if (a[idx] == 1)
    {
        // same grp
        if (ft + player <= S / 3)
            ans = min(ans, rec(idx + 1, ft + player, st));
        // other
        if (st + player <= S / 3)
            ans = min(ans, rec(idx + 1, ft, st + player) + 1);
        // third automatic
        ans = min(ans, rec(idx + 1, ft, st) + 1);
    }
    else if (a[idx] == 2)
    {
        // same grp
        if (st + player <= S / 3)
            ans = min(ans, rec(idx + 1, ft, st + player));
        // other
        if (ft + player <= S / 3)
            ans = min(ans, rec(idx + 1, ft + player, st) + 1);
        // third automatic
        ans = min(ans, rec(idx + 1, ft, st) + 1);
    }
    else
    {
        // same grp
        ans = min(ans, rec(idx + 1, ft, st));
        // other
        if (ft + player <= S / 3)
            ans = min(ans, rec(idx + 1, ft + player, st) + 1);
        // third automatic
        if (st + player <= S / 3)
            ans = min(ans, rec(idx + 1, ft, st + player) + 1);
    }
    return dp[idx][ft][st] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    S = accumulate(b.begin(), b.end(), 0LL);
    if (S % 3)
    {
        cout << -1 << endl;
        return 0;
    }
    dp.resize(n + 1, vector<vector<ll>>(S / 3 + 10, vector<ll>(S / 3 + 10, -1)));
    ll ans = rec(0, 0, 0);
    cout << (ans == 1e9 ? -1 : ans) << endl;
    return 0;
}