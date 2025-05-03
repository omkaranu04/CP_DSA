#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll x, y;
    cin >> x >> y;
    if (x + 1 >= y && (x - y + 1) % 9 == 0)
        cout << "Yes\n";
    else
        cout << "No\n";
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