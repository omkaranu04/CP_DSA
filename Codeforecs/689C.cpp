#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll poss(ll n)
{
    ll ans = 0;
    for (ll i = 2; i * i * i <= n; i++)
    {
        ans += n / (i * i * i);
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll m, n = -1;
    cin >> m;
    ll l = 0, r = 5e15;
    while (l < r)
    {
        ll mid = (l + r) / 2;
        if (poss(mid) < m)
            l = mid + 1;
        else
            r = mid;
    }
    if (poss(l) == m)
        n = l;
    cout << n << endl;
    return 0;
}