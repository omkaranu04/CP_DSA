#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
using position = pair<ll, ll>;
ll n;
position st, en;
ll dx[8] = {1, -1, 1, -1, 2, 2, -2, -2};
ll dy[8] = {2, 2, -2, -2, 1, -1, 1, -1};
bool check(ll x, ll y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}
void bfs()
{
    vector<vector<ll>> dist(n, vector<ll>(n, -1));
    queue<position> q;
    dist[st.first][st.second] = 0;
    q.push(st);

    while (!q.empty())
    {
        auto &[x, y] = q.front();
        q.pop();
        ll d = dist[x][y];

        for (ll i = 0; i < 8; i++)
        {
            ll nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny) && dist[nx][ny] == -1)
            {
                q.push({nx, ny});
                dist[nx][ny] = d + 1;

                if (nx == en.first && ny == en.second)
                {
                    cout << dist[nx][ny] << endl;
                    return;
                }
            }
        }
    }
    cout << dist[en.first][en.second] << endl;
    return;
}
void clove()
{
    cin >> n;
    cin >> st.first >> st.second;
    cin >> en.first >> en.second;
    bfs();
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
        clove();
    return 0;
}