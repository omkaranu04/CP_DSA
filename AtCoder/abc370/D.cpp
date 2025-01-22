#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll h, w, q;
    cin >> h >> w >> q;
    vector<set<ll>> g1(h), g2(w);
    for (ll i = 0; i < h; i++)
    {
        for (ll j = 0; j < w; j++)
        {
            g1[i].insert(j);
            g2[j].insert(i);
        }
    }
    while (q--)
    {
        ll r, c;
        cin >> r >> c;
        r--, c--;
        if (g1[r].count(c))
        {
            g1[r].erase(c);
            g2[c].erase(r);
            continue;
        }

        {
            auto it = g2[c].lower_bound(r);
            if (it != begin(g2[c]))
            {
                ll x = *prev(it);
                g1[x].erase(c);
                g2[c].erase(x);
            }
        }

        {
            auto it = g2[c].lower_bound(r);
            if (it != end(g2[c]))
            {
                ll x = *it;
                g1[x].erase(c);
                g2[c].erase(x);
            }
        }

        {
            auto it = g1[r].lower_bound(c);
            if (it != begin(g1[r]))
            {
                ll x = *prev(it);
                g2[x].erase(r);
                g1[r].erase(x);
            }
        }

        {
            auto it = g1[r].lower_bound(c);
            if (it != end(g1[r]))
            {
                ll x = *it;
                g2[x].erase(r);
                g1[r].erase(x);
            }
        }
    }
    ll ans = 0;
    for (ll i = 0; i < h; i++)
    {
        ans += g1[i].size();
    }
    cout << ans << endl;
    return 0;
}