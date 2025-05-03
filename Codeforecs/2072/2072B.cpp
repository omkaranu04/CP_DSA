#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if (n <= 2)
    {
        cout << "0\n";
        return;
    }
    ll cnt_down = 0, cnt_up = 0;
    for (auto x : s)
    {
        if (x == '_')
            cnt_down++;
        if (x == '-')
            cnt_up++;
    }
    if (cnt_up < 2)
    {
        cout << "0\n";
        return;
    }
    ll l = cnt_up / 2;
    ll r = cnt_up - l;
    ll ans = l * r * cnt_down;
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