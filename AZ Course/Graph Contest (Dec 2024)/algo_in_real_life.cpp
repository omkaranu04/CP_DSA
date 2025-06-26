#include <bits/stdc++.h>
using namespace std;
#define ll long long int
using state = array<ll, 3>;
#define endl "\n"
const ll mod = 1e9 + 7;
ll M, h, N, K;
vector<vector<pair<ll, ll>>> g;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M >> h >> N;
    g.resize(M + 1);
    for (ll i = 1; i <= N; i++)
    {
        ll s, d, p;
        cin >> s >> d >> p;
        g[s].push_back({d, p});
    }
    cin >> K;

    vector<vector<ll>> dp(M + 1, vector<ll>(K + 1, 1e18));
    dp[1][0] = 0;
    priority_queue<state, vector<state>, greater<state>> pq;
    pq.push({0, 1, 0}); // cost, city , flights
    while (!pq.empty())
    {
        auto tmp1 = pq.top();
        ll cost = tmp1[0], u = tmp1[1], k = tmp1[2];
        pq.pop();

        if (u == h)
        {
            cout << cost << endl;
            return 0;
        }
        if (cost != dp[u][k])
            continue;
        if (k == K)
            continue;

        for (auto tmp2 : g[u])
        {
            ll v = tmp2.first, price = tmp2.second;
            ll nc = cost + price;
            if (nc < dp[v][k + 1])
            {
                dp[v][k + 1] = nc;
                pq.push({nc, v, k + 1});
            }
        }
    }
    cout << -1;
    return 0;
}