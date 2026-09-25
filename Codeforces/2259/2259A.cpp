#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
void solve()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll f = 0;
    for (ll i = 0; i < n; i += k)
    {
        ll cnt = 0;
        for (ll j = 0; j < k; j++)
            if (s[i + j] == '1')
                cnt++;
        if (cnt == k)
            f++;
    }
    cout << f << endl;
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