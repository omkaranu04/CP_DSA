#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll f(ll a, ll b)
{
    if (a > b)
        return 1;
    if (a < b)
        return -1;
    return 0;
}
void solve()
{
    ll a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    ll wins = 0;
    if (f(a1, b1) + f(a2, b2) > 0)
        wins++;
    if (f(a1, b2) + f(a2, b1) > 0)
        wins++;
    if (f(a2, b1) + f(a1, b2) > 0)
        wins++;
    if (f(a2, b2) + f(a1, b1) > 0)
        wins++;
    cout << wins << endl;
    return;
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