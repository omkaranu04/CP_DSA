#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, q;
    cin >> n >> q;
    vector<ll> p(n), pos(n + 1);
    set<pair<ll, ll>> s;
    for (ll i = 0; i < n; i++)
    {
        cin >> p[i];
        pos[p[i]] = i;
        s.insert({i, p[i]});
    }
    ll last = n - 1;
    for (ll i = 0; i < q; i++)
    {
        ll a;
        cin >> a;
        s.erase({pos[a], a});
        last++;
        pos[a] = last;
        s.insert({last, a});
    }
    for (auto [a, b] : s)
        cout << b << " ";
    return 0;
}