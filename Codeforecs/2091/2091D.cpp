#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll per_row = k / n;
    if (k % n)
        per_row++;
    if (m >= 2 * per_row - 1)
        cout << 1 << endl;
    else
    {
        if (m == per_row)
            cout << m << endl;
        else
        {
            ll benches = min(per_row, m - per_row + 1);
            ll maxlen = (per_row + benches - 1) / benches;
            cout << maxlen << endl;
        }
    }
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