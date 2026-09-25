#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> par(n + 1);
    for (ll i = 1; i <= n; i++)
        par[a[i - 1]] = (i % 2);
    ll odd = (n + 1) / 2, even = n / 2;
    bool flag = true;
    for (ll i = 1; i <= n; i++)
    {
        if ((odd + even) % 2)
        {
            ll need = (odd > even) ? 1 : 0;
            if (par[i] != need)
                flag = false;
        }
        if (par[i] == 1)
            odd--;
        else
            even--;
    }
    cout << (flag ? "YES\n" : "NO\n");
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