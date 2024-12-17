#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll a, b;
    cin >> a >> b;
    if (a == 0 && b % 2 == 1)
    {
        cout << "NO" << endl;
    }
    else if (b == 0 && a % 2 == 1)
    {
        cout << "NO" << endl;
    }
    else if (a % 2 == 0 && b % 2 == 0)
    {
        cout << "YES" << endl;
    }
    else if (a % 2 == 0 && b % 2 == 1)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
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