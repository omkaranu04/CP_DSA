#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, d;
    cin >> n >> d;
    string s;
    cin >> s;
    ll ans = 0, filled = 0;
    for (auto i : s)
    {
        if (i == '.')
            ans++;
        else
            filled++;
    }
    cout << ans + min(filled, d) << endl;
    return;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}