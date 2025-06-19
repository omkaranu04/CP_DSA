#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll x, y, z;
    cin >> x >> y >> z;
    if (y == 0)
    {
        if (x > z + 1)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    else
    {
        if (x > z)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
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