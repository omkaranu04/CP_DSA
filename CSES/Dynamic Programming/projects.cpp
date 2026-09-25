#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
struct Project
{
    ll st, en, r;
};
bool comp(Project a, Project b) { return a.st < b.st; }
bool comp2(ll x, Project a) { return x < a.st; }
ll n;
vector<Project> p;
vector<ll> dp;
ll rec(ll i)
{
    if (i >= n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    // skip the project
    ll ans = rec(i + 1);
    ll ni = upper_bound(p.begin() + i + 1, p.end(), p[i].en, comp2) - p.begin();
    ans = max(ans, p[i].r + rec(ni));
    return dp[i] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    p.resize(n);
    dp.resize(n + 1, -1);
    for (ll i = 0; i < n; i++)
        cin >> p[i].st >> p[i].en >> p[i].r;
    sort(p.begin(), p.end(), comp);
    cout << rec(0) << endl;
    return 0;
}