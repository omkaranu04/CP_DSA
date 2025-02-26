#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> fib(51);
void solve()
{
    ll k;
    cin >> k;
    ll it = fib.size(), ans = 0;
    while (k > 0)
    {
        if (k >= fib[it])
        {
            k -= fib[it];
            ans++;
        }
        it--;
    }
    cout << ans << "\n";
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    fib[1] = 1;
    fib[2] = 1;
    for (ll i = 3; i < 51; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    while (t--)
    {
        solve();
    }
    return 0;
}