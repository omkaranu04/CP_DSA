#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] == '1' || s[n - 1] == '1')
    {
        cout << "YES\n";
        return;
    }
    if (s.find("11") != string::npos)
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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