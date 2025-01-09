#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    using namespace std;
    ll H, W;
    cin >> H >> W;

    ll X;
    ll x, y;
    cin >> X >> x >> y;

    vector<vector<ll>> slime_size(H + 2, vector<ll>(W + 2, 250000000000000000UL));
    for (ll i = 1; i <= H; ++i)
        for (ll j = 1; j <= W; ++j)
            cin >> slime_size[i][j];

    ll now_size = slime_size[x][y];

    vector<vector<bool>> visited(H + 2, vector<bool>(W + 2, false));

    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<>> pq;
    pq.emplace(0, x, y);
    visited[x][y] = true;

    while (!pq.empty())
    {
        const auto [size, x, y] = pq.top();
        pq.pop();

        if (size >= (now_size + X - 1) / X)
            break;

        now_size += size;

        for (const auto &[dx, dy] : vector<pair<int, int>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
        {
            if (!visited[x + dx][y + dy])
            {
                visited[x + dx][y + dy] = true;
                pq.emplace(slime_size[x + dx][y + dy], x + dx, y + dy);
            }
        }
    }

    cout << now_size << endl;

    return 0;
}