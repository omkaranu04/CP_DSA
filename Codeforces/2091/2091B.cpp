#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll strong = 0;
    ll currnum = 0, currmin = 1e9;
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i++)
    {
        currnum++;
        currmin = min(currmin, a[i]);
        if (currnum * currmin >= x)
        {
            strong++;
            currnum = 0;
            currmin = 1e9;
        }
    }
    cout << strong << endl;
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