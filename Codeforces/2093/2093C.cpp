#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
bool isprime(ll x)
{
    if (x == 1)
        return false;
    for (ll i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}
void solve()
{
    ll x, k;
    cin >> x >> k;
    if (x == 1 && k == 1)
        cout << "NO\n";
    else if (x == 1 && k == 2)
        cout << "YES\n";
    else
    {
        if (isprime(x) && k == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
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