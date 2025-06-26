#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll fib(ll n)
{
    if (n == 0 || n == 1)
        return n;
    ll a = 0, b = 1;
    ll idx = 2;
    while (b < n)
    {
        if (a + b == n)
            return idx;
        ll c = a + b;
        a = b;
        b = c;
        idx++;
    }
    return -1;
}
void solve()
{
    ll n;
    cin >> n;
    cout << fib(n) << endl;
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