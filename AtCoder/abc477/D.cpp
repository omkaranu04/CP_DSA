#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, q;
    cin >> n >> q;
    vector<pair<ll, pair<ll, char>>> queries(q);
    for (ll i = 0; i < q; i++)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll x;
            cin >> x;
            queries[i] = {1, {x, 0}};
        }
        if (t == 2)
        {
            char c;
            cin >> c;
            queries[i] = {2, {0, c}};
        }
    }
    vector<ll> tiles(n, 0), last(n, -1);
    string ans(n, 'a');
    char lastColor = 'a';
    ll lastIdx = -1;
    for (ll i = 0; i < q; i++)
    {
        ll t = queries[i].first;
        if (t == 2)
        {
            lastColor = queries[i].second.second;
            lastIdx = i;
        }
        if (t == 1)
        {
            ll x = queries[i].second.first;
            x--;
            if (!tiles[x])
            {
                if (lastIdx > last[x])
                    ans[x] = lastColor;
                tiles[x] = 1;
            }
            else
            {
                tiles[x] = 0;
                last[x] = i;
            }
        }
    }
    for (ll i = 0; i < n; i++)
    {
        if (!tiles[i] && lastIdx > last[i])
            ans[i] = lastColor;
    }
    ans += '\n';
    cout << ans;
    return 0;
}