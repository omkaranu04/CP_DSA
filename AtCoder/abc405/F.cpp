#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
struct fen
{
    ll n;
    vector<ll> f;
    fen(ll n) : n(n), f(n + 1, 0) {}
    void add(ll i, ll v)
    {
        for (; i <= n; i += i & -i)
            f[i] += v;
    }
    ll query(ll i)
    {
        ll s = 0;
        for (; i > 0; i -= i & -i)
            s += f[i];
        return s;
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N, M;
    cin >> N >> M;
    ll size = 2 * N;
    vector<pair<ll, ll>> segs(M);
    for (ll i = 0; i < M; i++)
    {
        ll a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        segs[i] = {a, b};
    }
    vector<ll> ecnt(size + 2, 0);
    for (auto &p : segs)
    {
        ecnt[p.first]++;
        ecnt[p.second]++;
    }
    for (ll i = 1; i <= size; i++)
        ecnt[i] += ecnt[i - 1];

    ll q;
    cin >> q;
    struct query
    {
        ll c, d, idx;
    };
    vector<query> queries(q);
    for (ll i = 0; i < q; i++)
    {
        cin >> queries[i].c >> queries[i].d;
        queries[i].idx = i;
    }
    sort(segs.begin(), segs.end(),
         [](auto &A, auto &B)
         { return A.first > B.first; });
    sort(queries.begin(), queries.end(),
         [](auto &A, auto &B)
         { return A.c > B.c; });

    fen fent(size);
    vector<ll> ans(q);
    ll p = 0;
    for (auto qs : queries)
    {
        while (p < M && segs[p].first > qs.c)
        {
            fent.add(segs[p].second, 1);
            p++;
        }
        ll cntend = ecnt[qs.d - 1] - ecnt[qs.c];
        ll inside = fent.query(qs.d - 1);
        ans[qs.idx] = cntend - 2LL * inside;
    }
    for (ll i = 0; i < q; i++)
        cout << ans[i] << endl;
    return 0;
}