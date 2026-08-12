#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool flag = false;
    for (ll i = 0; i < n - 1; i++)
    {
        if (2 * a[i + 1] > a[i] && 2 * a[i] > a[i + 1])
        {
            flag = true;
            break;
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
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