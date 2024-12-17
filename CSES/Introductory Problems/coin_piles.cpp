#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll a, b;
    cin >> a >> b;
    if ((a + b) % 3 == 0 && 2 * a >= b && 2 * b >= a)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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