#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
const ll mod = 1e9 + 7;
ll n, m;
vector<vector<ll>> g;
vector<ll> vis, topo, dp, indeg, par;

int main()
{
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	g.resize(n + 1);
	vis.resize(n + 1);
	dp.resize(n + 1, 0);
	indeg.resize(n + 1);
	par.resize(n + 1, -1);

	for (int i = 0; i < m; ++i)
	{
		ll a, b;
		cin >> a >> b;
		g[a].push_back(b);
		indeg[b]++;
	}

	queue<ll> q;
	for (ll i = 1; i <= n; i++) if (indeg[i] == 0) q.push(i);

	while (!q.empty())
	{
		ll u = q.front();
		topo.push_back(u);
		q.pop();

		for (auto v : g[u])
		{
			indeg[v]--;
			if (indeg[v] == 0) q.push(v);
		}
	}

	// for(auto x : topo) cout << x << " ";
	// cout << endl;

	dp[1] = 1;
	for(auto u : topo)
	{
		for(auto v : g[u])
		{
			dp[v] = (dp[v] % mod + dp[u] % mod) % mod;
		}
	}
	cout << dp[n];
}