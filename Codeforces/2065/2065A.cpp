#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    string s;
    cin >> s;
    ll n = s.length();
    if (s == "us")
    {
        cout << "i" << endl;
        return;
    }
    for (ll i = 0; i < n - 2; i++)
    {
        cout << s[i];
    }
    cout << "i" << endl;
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