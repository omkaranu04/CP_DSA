#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll nn;
    cin >> nn;
    set<ll> a, b;
    for (ll i = 0; i < nn; i++)
    {
        ll x;
        cin >> x;
        a.insert(x);
    }
    for (ll i = 0; i < nn; i++)
    {
        ll x;
        cin >> x;
        b.insert(x);
    }
    set<ll> u, n, mp;
    set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(u, u.begin()));
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(n, n.begin()));
    set_difference(u.begin(), u.end(), n.begin(), n.end(), inserter(mp, mp.begin()));
    for (auto x : mp)
        cout << x << " ";
    return 0;
}