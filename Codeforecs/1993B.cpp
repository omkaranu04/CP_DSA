#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> evens;
    ll max_odd = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
            evens.push_back(a[i]);
        else
            max_odd = max(max_odd, a[i]);
    }
    sort(evens.begin(), evens.end());
    if (evens.empty() || evens.size() == n)
    {
        cout << 0 << endl;
        return;
    }
    ll flag = 0;
    ll ans = evens.size();
    for (int i = 0; i < evens.size(); i++)
    {
        if (evens[i] > max_odd)
            flag = 1;
        else
        {
            max_odd += evens[i];
        }
    }
    if (flag)
        cout << ans + 1 << endl;
    else
        cout << ans << endl;
    return;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}