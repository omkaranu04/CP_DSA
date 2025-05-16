#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
ll rec(ll x)
{
    if (x == 1)
        return 1;
    else
        return 1 + 2 * rec(x / 2);
}
int main()
{
    ll H;
    cin >> H;
    ll ans = rec(H);
    cout << ans << endl;
}