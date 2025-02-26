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
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '.')
        {
            ans++;
        }
        else
        {
            filled++;
        }
    }
    ll toeat = min(filled, d);
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '@' && toeat > 0)
        {
            s[i] = '.';
            toeat--;
        }
    }
    cout << s << endl;
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