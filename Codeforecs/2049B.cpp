#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] == 's')
        s[0] = '.';
    if (s[n - 1] == 'p')
        s[n - 1] = '.';
    ll c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'p' || s[i] == '.')
            c1++;
        if (s[i] == 's' || s[i] == '.')
            c2++;
    }
    if (c1 == n || c2 == n)
        cout << "YES\n";
    else
        cout << "NO\n";
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