#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k, ans = 0;
vector<ll> a;
void rec(ll xori, ll idx, ll c)
{
    if (c == 0)
    {
        // cout << xori << " ";
        ans = max(ans, xori);
        return;
    }
    if (idx == n)
        return;
    // take
    rec(xori ^ a[idx], idx + 1, c - 1);
    // not take
    rec(xori, idx + 1, c);
}
int main(int argc, char const *argv[])
{
    cin >> n >> k;
    a.resize(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    if (k <= n - k)
        rec(0, 0, k);
    else
    {
        ll allXor = 0;
        for (ll i = 0; i < n; i++)
            allXor ^= a[i];
        rec(allXor, 0, n - k);
    }
    // cout << endl;
    cout << ans << endl;
    return 0;
}