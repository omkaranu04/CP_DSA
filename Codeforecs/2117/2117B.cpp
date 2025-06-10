#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    // alternating also works
    ll n;
    cin >> n;
    vector<ll> ans(n);
    for (ll i = 0; i < n - 1; i++)
        ans[i] = i + 2;
    ans[n - 1] = 1;
    for (ll i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
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