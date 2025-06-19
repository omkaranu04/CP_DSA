#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll x, y;
    cin >> x >> y;
    if (__gcd(x, y) > 1)
        cout << 0 << endl;
    else if (__gcd(x + 1, y) > 1 || __gcd(x, y + 1) > 1)
        cout << 1 << endl;
    else
        cout << 2 << endl;
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