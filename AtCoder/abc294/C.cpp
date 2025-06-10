#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < m; i++)
        cin >> b[i];
    vector<pair<ll, pair<ll, bool>>> c; // true -> a
    for (ll i = 0; i < n; i++)
    {
        c.push_back({a[i], {i, true}});
    }
    for (ll i = 0; i < m; i++)
    {
        c.push_back({b[i], {i, false}});
    }
    sort(c.begin(), c.end());
    for (ll i = 0; i < n + m; i++)
    {
        if (c[i].second.second)
            a[c[i].second.first] = i + 1;
        else
            b[c[i].second.first] = i + 1;
    }
    for (ll i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    for (ll i = 0; i < m; i++)
        cout << b[i] << " ";
    return 0;
}