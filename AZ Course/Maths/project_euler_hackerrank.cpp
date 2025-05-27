#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    ll mul3 = 3 * ((n / 3) * (n / 3 + 1)) / 2;
    ll mul5 = 5 * ((n / 5) * (n / 5 + 1)) / 2;
    ll mul15 = 15 * ((n / 15) * (n / 15 + 1)) / 2;
    ll ans = mul3 + mul5 - mul15;
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