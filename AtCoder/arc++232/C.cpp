#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll INF = 1000000;
ll n;
vector<ll> A, B, matchB, vis;
vector<vector<ll>> valid, tval;
bool kuhn(ll i, ll X)
{
    for (ll j = 0; j < n; j++)
    {
        if (!valid[i][j] || tval[i][j] > X || vis[j])
            continue;
        vis[j] = 1;
        if (matchB[j] < 0 || kuhn(matchB[j], X))
        {
            matchB[j] = i;
            return true;
        }
    }
    return false;
}
bool ask(ll X)
{
    matchB.assign(n, -1);
    for (ll i = 0; i < n; i++)
    {
        vis.assign(n, 0);
        if (!kuhn(i, X))
            return false;
    }
    return true;
}
ll hungry(ll n, const vector<vector<ll>> &a)
{
    vector<ll> u(n + 1, 0), v(n + 1, 0), p(n + 1, 0), way(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        p[0] = i;
        ll j0 = 0;
        vector<ll> minv(n + 1, LLONG_MAX), used(n + 1, 0);
        do
        {
            used[j0] = 1;
            ll i0 = p[j0], del = LLONG_MAX, j1 = 0;
            for (ll j = 1; j <= n; j++)
            {
                if (used[j])
                    continue;
                ll curr = a[i0][j] - u[i0] - v[j];
                if (curr < minv[j])
                {
                    minv[j] = curr;
                    way[j] = j0;
                }
                if (minv[j] < del)
                {
                    del = minv[j];
                    j1 = j;
                }
            }

            for (ll j = 0; j <= n; j++)
            {
                if (used[j])
                {
                    u[p[j]] += del;
                    v[j] -= del;
                }
                else
                {
                    minv[j] -= del;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);

        do
        {
            ll j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }

    ll cost = 0;
    for (ll j = 1; j <= n; j++)
        cost += a[p[j]][j];
    return cost;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        A.resize(n);
        B.resize(n);
        for (auto &x : A)
            cin >> x;
        for (auto &x : B)
            cin >> x;
        ll ans = LLONG_MAX;
        for (ll par = 0; par < 2; par++)
        {
            valid.assign(n, vector<ll>(n, 0));
            tval.assign(n, vector<ll>(n, 0));
            vector<ll> tmp, cand;
            for (ll i = 0; i < n; i++)
            {
                for (ll j = 0; j < n; j++)
                {
                    ll d = B[j] - A[i];
                    if ((((d % 2) + 2) % 2) != par)
                        continue;
                    valid[i][j] = 1;
                    ll s = llabs(A[i] + B[j]), df = llabs(d);
                    tval[i][j] = min(s, df);
                    tmp.push_back(tval[i][j]);
                    cand.push_back(s);
                    cand.push_back(df);
                }
            }
            if (tmp.empty())
                continue;
            sort(tmp.begin(), tmp.end());
            tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

            if (!ask(tmp.back()))
                continue;

            ll lo = 0, hi = tmp.size() - 1;
            while (lo < hi)
            {
                ll mid = (lo + hi) / 2;
                if (ask(tmp[mid]))
                    hi = mid;
                else
                    lo = mid + 1;
            }
            ll k1 = tmp[lo];
            cand.push_back(k1);
            sort(cand.begin(), cand.end());
            cand.erase(unique(cand.begin(), cand.end()), cand.end());

            vector<vector<ll>> cost(n + 1, vector<ll>(n + 1, INF));
            for (auto k : cand)
            {
                if (k < k1)
                    continue;
                if (k >= ans)
                    break;
                for (ll i = 0; i < n; i++)
                {
                    for (ll j = 0; j < n; j++)
                    {
                        ll c = INF;
                        if (valid[i][j])
                        {
                            if (B[j] - A[i] == k)
                                c = 0;
                            else if (llabs(A[i] + B[j]) <= k)
                                c = 1;
                            else if (llabs(B[j] - A[i]) <= k)
                                c = 2;
                        }
                        cost[i + 1][j + 1] = c;
                    }
                }
                ll m = hungry(n, cost);
                if (m < INF)
                    ans = min(ans, k + m);
            }
        }
        if (ans == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}