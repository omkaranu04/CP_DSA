#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    ll a, x, y;
    cin >> a >> x >> y;
    bool poss = false;
    for (ll b = -100; b <= 200; b++)
    {
        if (b == a)
            continue;
        if (abs(b - x) < abs(a - x) && abs(b - y) < abs(a - y))
        {
            poss = true;
            break;
        }
    }
    if (poss)
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