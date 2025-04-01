#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#define ll long long int
#define endl "\n"
ll N;
ll solve(ll a, ll b, ll c)
{
    ll l = 0, r = 600000001;
    while (r - l > 1)
    {
        ll mid = (l + r) / 2;
        if (a * mid * mid + b * mid + c <= 0)
            l = mid;
        else
            r = mid;
    }
    if (a * l * l + b * l + c == 0)
        return l;
    return -1;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    ll d;
    for (d = 1; d * d * d <= N; d++)
    {
        if (N % d != 0)
            continue;
        ll temp = N / d;
        ll k = solve(3, 3 * d, d * d - temp);
        if (k > 0)
        {
            cout << k + d << " " << k << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}