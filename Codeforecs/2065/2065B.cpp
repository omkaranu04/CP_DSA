#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    string s;
    cin >> s;
    ll n = s.length();
    for (ll i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            cout << 1 << endl;
            return;
        }
    }
    cout << n << endl;
    return;
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