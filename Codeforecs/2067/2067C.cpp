#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool contains7(ll n)
{
    while (n)
    {
        if (n % 10 == 7)
            return true;
        n /= 10;
    }
    return false;
}
void solve()
{
    ll n;
    cin >> n;
    ll ans = 1e18;
    for (ll add = 9; add <= 999999999999999; add = add * 10 + 9)
    {
        ll temp = n;
        ll tans = 0;

        while (!contains7(temp))
        {
            temp += add;
            tans++;
        }

        ans = min(ans, tans);
    }

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