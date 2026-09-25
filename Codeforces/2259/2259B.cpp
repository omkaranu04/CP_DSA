#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    ll c1 = 0, c2 = 0, c3 = 0;
    for (auto &x : a)
    {
        if (x % 2)
            c1++;
        if (x % 4 == 0)
            c2++;
        if (x % 4 == 2)
            c3++;
    }
    cout << max(c1, max(c2, c3)) << endl;
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