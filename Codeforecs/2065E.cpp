#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    if (k > max(m, n) || k < abs(m - n))
    {
        cout << "-1\n";
        return;
    }
    bool f = true;
    if (n >= m)
    {
        // cout << "j";
        cout << string(k, '0');
        n -= k;
    }
    else
    {
        // cout << "j";
        cout << string(k, '1');
        f = false;
        m -= k;
    }
    // cout << endl
    //  << m << " " << n << endl;

    for (ll i = 0; i < min(m, n); i++)
    {
        // cout << "l";
        if (f)
            cout << "10";
        else
            cout << "01";
    }
    ll x = min(m, n);
    m -= x;
    n -= x;
    // cout << endl
    //      << m << " " << n << endl;
    if (n >= m)
    {
        // cout << "i";
        cout << string(n - m, '0');
        n -= (n - m);
    }
    else
    {
        cout << string(m - n, '1');
        m -= (m - n);
    }
    cout << '\n';
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