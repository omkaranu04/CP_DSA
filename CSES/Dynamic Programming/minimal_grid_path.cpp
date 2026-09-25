#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MAXN = 3010;
ll N;
char g[MAXN][MAXN];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (ll i = 1; i <= N; i++)
        for (ll j = 1; j <= N; j++)
            cin >> g[i][j];
    string ans;

    // BFS
    vector<pair<ll, ll>> curr;
    curr.push_back({1, 1});
    ans.push_back(g[1][1]);
    for (ll s = 1; s <= 2 * N - 2; s++)
    {
        char best = 'Z' + 1;
        for (auto [i, j] : curr)
        {
            if (i + 1 <= N)
                best = min(best, g[i + 1][j]);
            if (j + 1 <= N)
                best = min(best, g[i][j + 1]);
        }

        vector<pair<ll, ll>> next;
        for (auto [i, j] : curr)
        {
            if (i + 1 <= N && g[i + 1][j] == best)
                next.push_back({i + 1, j});
            if (j + 1 <= N && g[i][j + 1] == best)
                next.push_back({i, j + 1});
        }
        next.erase(unique(next.begin(), next.end()), next.end());

        curr.swap(next);
        // cout << "best: " << best << endl;
        ans += best;
    }
    cout << ans;
    return 0;
}