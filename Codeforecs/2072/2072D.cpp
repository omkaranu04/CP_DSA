#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 0, l = 0, r = 0;
    for (ll i = 0; i < n; i++)
    {
        int c1 = 0, c2 = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
                c1++;
            if (a[j] > a[i])
                c2++;

            if (ans >= c2 - c1)
            {
                ans = c2 - c1;
                l = i;
                r = j;
            }
        }
    }
    cout << l + 1 << " " << r + 1 << endl;
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