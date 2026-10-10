#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MAXN = 500010;
ll mxR[MAXN], mnR[MAXN], hiA[MAXN], suff[MAXN];
ll lo[MAXN], hi[MAXN], nxt[MAXN], par[MAXN], predP[MAXN], q[MAXN];
bool onP[MAXN], outVis[MAXN];
ll findNext(ll x)
{
    ll r = x;
    while (nxt[r] != r)
        r = nxt[r];
    while (nxt[x] != r)
    {
        ll t = nxt[x];
        nxt[x] = r;
        x = t;
    }
    return r;
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
        ll N, M;
        cin >> N >> M;
        for (ll i = 0; i <= N + 2; i++)
        {
            mxR[i] = 0;
            mnR[i] = N + 1;
        }
        for (ll i = 1; i <= M; i++)
        {
            ll L, R;
            cin >> L >> R;
            mxR[L] = max(mxR[L], R);
            mnR[L] = min(mnR[L], R);
        }
        hiA[0] = 0;
        for (ll i = 1; i <= N; i++)
            hiA[i] = max(hiA[i - 1], mxR[i]);
        suff[N + 1] = N + 1;
        for (ll i = N; i >= 1; i--)
            suff[i] = min(mnR[i], suff[i + 1]);
        for (ll i = 0; i <= N; i++)
        {
            lo[i] = max(hiA[i], i) + 1LL;
            hi[i] = suff[i + 1];
        }

        // BFS - 1
        for (ll i = 1; i <= N + 2; i++)
            nxt[i] = i;
        ll h = 0, t = 0;
        q[t++] = 0;
        bool flag = false;
        while (h < t)
        {
            ll u = q[h++];
            if (lo[u] > hi[u])
                continue;
            for (ll w = findNext(lo[u]); w <= hi[u]; w = findNext(w + 1))
            {
                nxt[w] = w + 1;
                par[w] = u;
                if (w == N + 1)
                    flag = true;
                else
                    q[t++] = w;
            }
        }
        if (!flag)
        {
            cout << "No\n";
            continue;
        }
        for (ll i = 0; i <= N; i++)
            onP[i] = false;
        for (ll i = par[N + 1]; i != 0; i = par[i])
        {
            onP[i] = true;
            predP[i] = par[i];
        }

        // BFS - 2
        for (ll i = 1; i <= N + 2; i++)
            nxt[i] = i;
        for (ll i = 0; i <= N + 1; i++)
            outVis[i] = false;
        h = 0;
        t = 0;
        outVis[0] = true;
        q[t++] = 0;
        flag = false;

        auto visitOut = [&](ll v)
        {
            if (v != 0 && !outVis[v])
            {
                outVis[v] = true;
                q[t++] = v;
            }
        };
        auto visitIn = [&](ll w)
        {
            if (w == N + 1)
            {
                flag = true;
                return;
            }
            if (!onP[w])
                visitOut(w);
            else
                visitOut(predP[w]);
        };

        while (h < t && !flag)
        {
            ll u = q[h++];
            if (onP[u] && nxt[u] == u)
            {
                nxt[u] = u + 1;
                visitIn(u);
            }
            if (lo[u] > hi[u])
                continue;
            for (ll w = findNext(lo[u]); w <= hi[u] && !flag; w = findNext(w + 1))
            {
                nxt[w] = w + 1;
                visitIn(w);
            }
        }
        if (flag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}