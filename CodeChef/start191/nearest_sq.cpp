#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    ll b = (ll)sqrt(n);
    if (b * b <= n && b * b >= 1)
        cout << b * 1LL * b << endl;
    else
        cout << (b - 1) * 1LL * (b - 1) << endl;
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