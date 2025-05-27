/*
    Warnsdorff's Heuristic
    1. We can start from any initial position of the knight on the board
    2. We always move to an adjacent, unvisited square with minimal
        degree (minimum number of unvisited adjacent).
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
const ll N = 8;
ll startx, starty;
ll pos[N][N], deg[N][N], vis[N][N];
ll dx[N] = {-2, -1, 1, 2, 2, 1, -1, -2};
ll dy[N] = {1, 2, 2, 1, -1, -2, -2, -1};

bool check(ll x, ll y)
{
    return x >= 0 && x < N && y >= 0 && y < N;
}

void init()
{
    for (ll x = 0; x < N; x++)
    {
        for (ll y = 0; y < N; y++)
        {
            deg[x][y] = 0;
            for (ll i = 0; i < N; i++)
            {
                ll nx = x + dx[i], ny = y + dy[i];
                if (check(nx, ny))
                    deg[x][y]++;
            }
        }
    }
}
void mark(ll id, ll x, ll y)
{
    pos[x][y] = id;
    vis[x][y] = 1;
    for (ll i = 0; i < N; i++)
    {
        ll nx = x + dx[i], ny = y + dy[i];
        if (check(nx, ny) && !vis[nx][ny])
            deg[nx][ny]--;
    }
}
void unmark(ll x, ll y)
{
    pos[x][y] = -1;
    vis[x][y] = 0;
    for (ll i = 0; i < N; i++)
    {
        ll nx = x + dx[i], ny = y + dy[i];
        if (check(nx, ny) && !vis[nx][ny])
            deg[nx][ny]++;
    }
}
bool check(ll x, ll y, ll cnt)
{
    mark(cnt, x, y);

    if (cnt >= N * N)
        return true;

    vector<pair<ll, pair<ll, ll>>> nextmoves;

    for (ll i = 0; i < N; i++)
    {
        ll nx = x + dx[i], ny = y + dy[i];
        if (check(nx, ny) && !vis[nx][ny])
            nextmoves.push_back({deg[nx][ny], {nx, ny}});
    }

    sort(nextmoves.begin(), nextmoves.end());

    for (auto move : nextmoves)
    {
        ll nx = move.second.first, ny = move.second.second;
        if (check(nx, ny, cnt + 1))
            return true;
    }

    unmark(x, y);
    return false;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> startx >> starty;
    startx--, starty--;
    swap(startx, starty);

    memset(pos, -1, sizeof(pos));
    memset(vis, 0, sizeof(vis));
    memset(deg, 0, sizeof(deg));

    init();

    if (check(startx, starty, 1))
    {
        for (ll i = 0; i < N; i++)
        {
            for (ll j = 0; j < N; j++)
            {
                cout << pos[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}