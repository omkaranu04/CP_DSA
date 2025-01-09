#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll x;
    cin >> x;
    if (x % 33 == 0)
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