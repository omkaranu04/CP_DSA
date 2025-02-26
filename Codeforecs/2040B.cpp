#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    if (n == 2 || n == 3 || n == 4)
    {
        cout << 2 << endl;
        return;
    }
    ll start = 5;
    ll temp = 6;
    ll ans = 3;
    while (1)
    {
        if (n >= start && n <= 2 * start)
        {
            cout << ans << endl;
            return;
        }
        start += temp;
        temp *= 2;
        ans++;
    }
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