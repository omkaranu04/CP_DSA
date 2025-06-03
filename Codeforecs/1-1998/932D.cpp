#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define INF 1e18
// 1 is always the root
const ll mod = 1e9 + 7;
const ll LOGN = 20;
const ll MAXN = 400005;
ll Q;
ll parent[LOGN][MAXN], sum[LOGN][MAXN], w[MAXN];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> Q;

    w[1] = 0;
    for (ll i = 1; i < LOGN; i++)
    {
        parent[i][1] = 0;
        sum[i][1] = INF;
    }

    ll last = 0, curr = 1;

    while (Q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll p, q;
            cin >> p >> q;
            p ^= last; // R
            q ^= last; // W

            curr++;
            w[curr] = q;

            // find next valid ancestor
            if (w[p] >= w[curr])
            {
                parent[0][curr] = p;
            }
            else
            {
                ll from = p;
                for (ll i = LOGN - 1; i >= 0; i--)
                {
                    if (parent[i][from] != 0 && w[parent[i][from]] < w[curr])
                        from = parent[i][from];
                }
                parent[0][curr] = parent[0][from];
            }
        }
        else
        {
        }
    }
    return 0;
}