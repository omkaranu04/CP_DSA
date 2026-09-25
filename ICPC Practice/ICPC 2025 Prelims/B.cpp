#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
void solve()
{
    ll n, d;
    cin >> n >> d;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    ll flag = 0;
    ll i;
    for (i = 0; i < n;)
    {
        if (llabs(a[i] - a[i + 1]) <= d)
            i += 2;
        else
        {
            flag++;
            i++;
        }
    }
    if (flag <= 1)
        cout << "YES\n";
    else
        cout << "NO\n";
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