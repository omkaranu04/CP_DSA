#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll H, W, D;
    cin >> H >> W >> D;
    set<pair<ll, ll>> floor_cells;
    for (ll i = 0; i < H; i++)
    {
        for (ll j = 0; j < W; j++)
        {
            char c;
            cin >> c;
            if (c == '.')
                floor_cells.insert({i, j});
        }
    }
    map<pair<ll, ll>, set<pair<ll, ll>>> cells;
    for (auto xx : floor_cells)
    {
        ll x1 = xx.first, y1 = xx.second;
        for (auto yy : floor_cells)
        {
            ll x2 = yy.first, y2 = yy.second;
            ll dis = abs(x1 - x2) + abs(y1 - y2);
            if (dis <= D)
                cells[{x1, y1}].insert({x2, y2});
        }
    }
    ll ans = 0;
    for (auto xx : cells)
    {
        for (auto yy : cells)
        {
            if (xx != yy)
            {
                // find the union of both the sets and then take max with ans
                set<pair<ll, ll>> temp;
                set_union(xx.second.begin(), xx.second.end(), yy.second.begin(), yy.second.end(), inserter(temp, temp.begin()));
                ans = max(ans, (ll)temp.size());
            }
        }
    }
    cout << ans << endl;
    return 0;
}