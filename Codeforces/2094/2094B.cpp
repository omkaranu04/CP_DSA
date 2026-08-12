#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, m, l, r;
    cin >> n >> m >> l >> r;
    if (m <= r)
        cout << 0 << " " << m << endl;
    else
        cout << r - m << " " << r << endl;
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