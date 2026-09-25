#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MAXN = 1010;
ll N, M;
ll a[MAXN], b[MAXN], dp[MAXN][MAXN];
vector<ll> ans;
ll rec(ll i, ll j)
{
    if (i > N || j > M)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    ll ans = 0;
    ans = max(ans, rec(i + 1, j));
    ans = max(ans, rec(i, j + 1));
    if (a[i] == b[j])
        ans = max(ans, 1 + rec(i + 1, j + 1));
    return dp[i][j] = ans;
}
void build(ll i, ll j)
{
    if (i > N || j > M)
        return;
    if (a[i] == b[j] && rec(i, j) == 1 + rec(i + 1, j + 1))
    {
        ans.push_back(a[i]);
        build(i + 1, j + 1);
    }
    else if (rec(i + 1, j) >= rec(i, j + 1))
        build(i + 1, j);
    else
        build(i, j + 1);
    return;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> N >> M;
    for (ll i = 1; i <= N; i++)
        cin >> a[i];
    for (ll i = 1; i <= M; i++)
        cin >> b[i];
    cout << rec(1, 1) << endl;
    build(1, 1);
    for (auto &x : ans)
        cout << x << " ";
    return 0;
}