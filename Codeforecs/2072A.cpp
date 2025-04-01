#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, k, p;
    cin >> n >> k >> p;
    ll max_poss = n * p;
    ll min_poss = -max_poss;
    if (k < min_poss || k > max_poss)
    {
        cout << "-1\n";
        return;
    }
    ll ans = abs(k) / p;
    ll rem = abs(k) % p;
    if (ans > n)
        ans = -1;
    if (rem > 0)
        ans++;
    if (ans > n)
        ans = -1;
    cout << ans << "\n";
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}