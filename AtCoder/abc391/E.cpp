#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> dp;
ll n;
string s;
ll pow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll tmp = pow(a, b / 2);
    if (b % 2)
        return tmp * tmp * a;
    return tmp * tmp;
}
pair<char, ll> rec(ll l, ll r)
{
    if (l + 1 == r)
        return make_pair(s[l], 1);
    ll m1 = (2 * l + r) / 3;
    ll m2 = (l + 2 * r) / 3;
    auto [v1, c1] = rec(l, m1);
    auto [v2, c2] = rec(m1, m2);
    auto [v3, c3] = rec(m2, r);

    if (v1 == v2 && v2 == v3)
        return make_pair(v1, c1 + c2 + c3 - max({c1, c2, c3}));
    if (v1 == v2)
        return make_pair(v1, min(c1, c2));
    if (v2 == v3)
        return make_pair(v2, min(c2, c3));
    if (v1 == v3)
        return make_pair(v1, min(c1, c3));

    return make_pair(v1, 1);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> s;
    n = pow(3, n);
    auto ans = rec(0, n);
    cout << ans.second << endl;
    return 0;
}