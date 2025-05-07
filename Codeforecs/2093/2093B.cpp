#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
void solve()
{
    string n;
    cin >> n;
    ll sm_idx = -1;
    for (ll i = 0; i < n.length(); i++)
    {
        if (n[i] > '0')
            sm_idx = i;
    }
    ll ans = 0;
    for (ll i = 0; i < sm_idx; i++)
    {
        if (n[i] > '0')
            ans++;
    }
    ans += (n.length() - sm_idx - 1);
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