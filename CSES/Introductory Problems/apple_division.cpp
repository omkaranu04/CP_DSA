#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
vector<ll> p;
ll solve(ll i, ll sum1, ll sum2)
{
    if (i == n)
        return abs(sum1 - sum2);
    return min(solve(i + 1, sum1 + p[i], sum2), solve(i + 1, sum1, sum2 + p[i]));
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    p.resize(n);
    for (auto &i : p)
        cin >> i;
    ll sum1 = 0, sum2 = 0;
    cout << solve(0, sum1, sum2) << endl;
    return 0;
}