#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    string s, f;
    cin >> s >> f;
    int a = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0' && f[i] == '1')
            a++;
        if (s[i] == '1' && f[i] == '0')
            r++;
    }
    cout << max(a, r) << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}