#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll x, n;
    cin >> x >> n;
    vector<ll> p(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    set<ll> positions = {0, x};
    multiset<ll> segments = {x};
    for (auto light : p)
    {
        auto it = positions.upper_bound(light);
        auto r = *it;
        auto l = *prev(it);

        segments.erase(segments.find(r - l));
        segments.insert(light - l);
        segments.insert(r - light);

        positions.insert(light);

        cout << *segments.rbegin() << " ";
    }
    return 0;
}