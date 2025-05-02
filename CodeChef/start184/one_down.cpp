#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '0' && t[i] == '1')
        {
            cout << "No\n";
            return;
        }
    }
    ll s_ones = count(s.begin(), s.end(), '1');
    ll t_ones = count(t.begin(), t.end(), '1');

    if (s_ones >= t_ones && (s_ones - t_ones) % 2 == 0)
        cout << "Yes\n";
    else
        cout << "No\n";
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