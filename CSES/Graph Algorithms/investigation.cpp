#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, m;
vector<vector<pair<ll, ll>>> g;
vector<ll> vis, dist, cnt, minf, maxf;
void dijkstra()
{
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	dist[1] = 0;
	cnt[1] = 1;
	minf[1] = 0;
	maxf[1] = 0;
	pq.push({0, 1});

	while (!pq.empty())
	{
		auto [ww, u] = pq.top();
		pq.pop();

		if (vis[u]) continue;
		vis[u] = 1;

		for (auto [v, w] : g[u])
		{
			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				cnt[v] = cnt[u];
				minf[v] = minf[u]+1;
				maxf[v] = maxf[u]+1;
				pq.push({dist[v], v});
			}
			else if (dist[v] == dist[u] + w)
			{
				minf[v] = min(minf[v], minf[u]+1);
				maxf[v] = max(maxf[v], maxf[u]+1);
				cnt[v] += cnt[u];
				cnt[v] %= mod;
			}
		}
	}

	cout << dist[n] << " " << cnt[n] << " ";
	cout<<minf[n]<<" "<<maxf[n];
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	g.resize(n + 1);
	vis.resize(n + 1, 0);
	dist.resize(n + 1, 1e18);
	cnt.resize(n + 1, 0);
	minf.resize(n + 1, 1e18);
	maxf.resize(n + 1, -1e18);

	for (ll i = 0; i < m; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({b, c});
	}

	dijkstra();

	return 0;
}