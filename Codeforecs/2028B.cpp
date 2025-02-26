#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, b, c;
    cin >> n >> b >> c;
    if (c > n - 1)
    {
        cout << n << endl;
        return;
    }
    if (b == 0)
    {
        if (c > n - 3)
        {
            cout << n - 1 << endl;
        }
        else
            cout << "-1\n";
    }
    else
    {
        cout << n - max(0ll, 1 + (n - c - 1) / b) << endl;
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