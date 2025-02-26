#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
vector<ll> dp;
ll rec(ll x)
{
    if (x == 0)
        return 0;

    if (dp[x] != -1)
        return dp[x];

    // string s = to_string(x);
    multiset<ll> st;
    // for (auto i : s)
    // {
    //     st.insert(i - '0');
    // }
    ll cp = x;
    while (cp)
    {
        st.insert(cp % 10);
        cp /= 10;
    }
    ll ans = 1e9;

    for (auto i : st)
    {
        if (x >= i && i != 0)
            ans = min(ans, 1 + rec(x - i));
    }

    return dp[x] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    dp.resize(n + 1, -1);
    cout << rec(n) << endl;
    return 0;
}