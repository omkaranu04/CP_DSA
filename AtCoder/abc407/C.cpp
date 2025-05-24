#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    ll ans = 0;
    for (ll i = s.length() - 1; i >= 0; i--)
    {
        ll x = s[i] - '0';
        ans += (x - ans % 10 + 10) % 10;
    }
    cout << ans + s.length();
    return 0;
}