#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    string res;
    for (ll i = 0; i < n; i++)
    {
        if (i == 0)
            res += '0';
        else if (i == 1)
            res += '1';
        else
            res += '0';
    }
    cout << res << endl;
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