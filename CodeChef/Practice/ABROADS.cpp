#include <bits/stdc++.h>
using namespace std;
#define ll long long int
struct DSU
{
    ll n;
    vector<ll> par, sz, sum, pop;
    DSU(ll _n, const vector<ll> &initPop)
    {
        n = _n;
        sz.resize(n + 1, 1);
        // pop[i] = population of city i
        pop = initPop;
        // sum[i] = total population of the component, if i is representative/root
        sum = initPop;
        par.resize(n + 1);
        for (ll i = 0; i <= n; i++)
            par[i] = i;
    }
    ll find(ll x)
    {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }
    bool merge(ll x, ll y, multiset<ll> &comps)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        // remove old component populations
        comps.erase(comps.find(sum[x]));
        comps.erase(comps.find(sum[y]));
        if (sz[x] > sz[y])
            swap(x, y);
        par[x] = y;
        sz[y] += sz[x];
        // new component population
        sum[y] += sum[x];
        // insert the new component population
        comps.insert(sum[y]);
        return true;
    }
    void chPop(ll x, ll val, multiset<ll> &comps)
    {
        ll rx = find(x);
        // remove old component population
        comps.erase(comps.find(sum[rx]));
        // update the component population
        sum[rx] += (val - pop[x]);
        // insert the new component population
        comps.insert(sum[rx]);
        // update the individual city population
        pop[x] = val;
    }
};
struct Query
{
    ll t;
    // query - 1
    ll r;
    // query - 2
    ll c, nval, oval;
};
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<ll> Pop(N + 1);
    for (ll i = 1; i <= N; i++)
        cin >> Pop[i];
    vector<pair<ll, ll>> edges(M + 1);
    for (ll i = 1; i <= M; i++)
    {
        ll x, y;
        cin >> x >> y;
        edges[i] = {x, y};
    }
    vector<Query> queries(Q + 1);
    // delCnt[i] = number of times road i occurs in a deletion query
    vector<ll> delCnt(M + 1, 0);
    // currPop will be changed while reading queries -> currPop will have population AFTER ALL queries
    vector<ll> currPop = Pop;
    for (ll i = 1; i <= Q; i++)
    {
        char t;
        cin >> t;
        queries[i].t = t;
        if (t == 'D')
        {
            ll k;
            cin >> k;
            queries[i].r = k;
            delCnt[k]++;
        }
        else
        {
            ll a, x;
            cin >> a >> x;
            queries[i].c = a;
            queries[i].nval = x;
            // save the population before this update
            queries[i].oval = currPop[a];
            currPop[a] = x;
        }
    }

    DSU dsu(N, currPop);

    // comps -> contains the population of every connected component
    multiset<ll> comps;

    for (ll i = 1; i <= N; i++)
        comps.insert(currPop[i]);

    // Add only those roads which were NEVER deleyed even after Q queries
    for (ll i = 1; i <= M; i++)
    {
        if (!delCnt[i])
            dsu.merge(edges[i].first, edges[i].second, comps);
    }
    vector<ll> ans(Q + 1);
    // Process queries in reverse so that DSU is valid in reverse
    for (ll i = Q; i >= 1; i--)
    {
        // answer after every query
        ans[i] = *comps.rbegin();

        if (queries[i].t == 'D')
        {
            // in reverse -> add the road back
            ll road = queries[i].r;
            delCnt[road]--;
            if (delCnt[road] == 0)
            {
                auto [x, y] = edges[road];
                dsu.merge(x, y, comps);
            }
        }
        else
        {
            ll city = queries[i].c;
            ll oval = queries[i].oval;
            dsu.chPop(city, oval, comps);
        }
    }
    for (ll i = 1; i <= Q; i++)
        cout << ans[i] << "\n";
    return 0;
}