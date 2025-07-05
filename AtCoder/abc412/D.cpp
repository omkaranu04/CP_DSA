#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long
#define endl "\n"
const ll mod = 1e9 + 7;
ll N, M;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    ll id[8][8], idx = 0;
    for (ll i = 0; i < N; i++)
    {
        for (ll j = i + 1; j < N; j++)
            id[i][j] = id[j][i] = idx++;
    }
    ul G = 0;
    for (ll i = 0; i < M; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        G |= (1ULL << id[u][v]);
    }

    // brute force bad
    vector<ll> p(N);
    for (ll i = 0; i < N; i++)
        p[i] = i;
    ll ans = 1e18, GAP = N - 1, SPLIT = 1LL << GAP;

    do
    {
        for (ll sp = 0; sp < SPLIT; sp++)
        {
            ll len = 1, ok = 1;
            for (ll i = 0; i < GAP; i++)
            {
                if (sp & (1LL << i))
                {
                    if (len < 3)
                    {
                        ok = 0;
                        break;
                    }
                    len = 1;
                }
                else
                    len++;
            }

            if (ok == 0 || len < 3)
                continue;

            ul H = 0;
            ll fidx = 0;
            for (ll i = 0; i < GAP; i++)
            {
                if (sp & (1LL << i))
                {
                    for (ll j = fidx; j < i; j++)
                        H |= 1ULL << id[p[j]][p[j + 1]];
                    H |= 1ULL << id[p[fidx]][p[i]];
                    fidx = i + 1;
                }
            }

            for (ll j = fidx; j < N - 1; j++)
                H |= 1ULL << id[p[j]][p[j + 1]];
            H |= 1ULL << id[p[fidx]][p[N - 1]];

            ll cost = __builtin_popcountll(H ^ G);
            if (cost < ans)
            {
                ans = cost;
                if (ans == 0)
                {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }

    } while (next_permutation(p.begin(), p.end()));
    cout << ans;
    return 0;
}