#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};
ll h, w, A, B, C, D;
bool check(ll r, ll c)
{
    if (r < 0 || r >= h || c < 0 || c >= w)
        return false;
    return true;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> grid[i][j];
        }
    }
    cin >> A >> B >> C >> D;
    A--, B--, C--, D--;
    vector<vector<ll>> dist(h, vector<ll>(w, -1));
    deque<array<ll, 3>> q;
    q.push_back({0, A, B});
    while (!q.empty())
    {
        auto [d, r, c] = q.front();
        q.pop_front();
        if (dist[r][c] != -1)
            continue;
        dist[r][c] = d;
        for (int i = 0; i < 4; i++)
        {
            // next immediate step
            ll nr = r + dx[i], nc = c + dy[i];
            if (!check(nr, nc))
                continue;
            if (grid[nr][nc] == '.')
                q.push_front({d, nr, nc});
            else
                q.push_back({d + 1, nr, nc}); // proceed with a kick

            // the 2nd step check
            nr += dx[i], nc += dy[i];
            if (!check(nr, nc))
                continue;
            q.push_back({d + 1, nr, nc}); // proceed with a kick
        }
    }
    cout << dist[C][D] << endl;
    return 0;
}