#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void solve()
{
    ll n, k, l;
    cin >> n >> k >> l;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll teams = 1, currmemcount = 1, prevrating = a[0];
    for (ll i = 1; i < n; i++)
    {
        if (currmemcount + 1 <= k && abs(prevrating - a[i]) <= l)
        {
            currmemcount++;
            prevrating = min(prevrating, a[i]);
        }
        else
        {
            teams++;
            currmemcount = 1;
            prevrating = a[i];
        }
    }
    cout << teams << endl;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}