#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    ll range = n - (n - k + 1) + 1;
    if (range % 2 == 0)
        ans = range / 2;
    else
    {
        if (n % 2 || (n - k + 1) % 2)
            ans = range / 2 + 1;
        else
            ans = range / 2;
    }
    if (ans % 2 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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