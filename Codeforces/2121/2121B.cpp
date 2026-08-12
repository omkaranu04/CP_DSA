#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> freq(26, 0);
    for (auto c : s)
        freq[c - 'a']++;
    bool ok = false;
    for (ll i = 1; i <= n - 2 && !ok; i++)
        if (freq[s[i] - 'a'] >= 2)
            ok = true;
    cout << (ok ? "YES\n" : "NO\n");
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