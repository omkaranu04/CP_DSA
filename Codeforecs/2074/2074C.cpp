#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool check(ll a, ll b, ll c)
{
    return (a + b > c) && (a + c > b) && (b + c > a);
}
void solve()
{
    ll x;
    cin >> x;
    ll ans = -1;
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            ll y = (1 << j) | (i << i);
            if (check(x, y, x ^ y) && y < x)
            {
                ans = y;
                break;
            }
        }
    }
    // cout << "Ans : ";
    cout << ans << endl;
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