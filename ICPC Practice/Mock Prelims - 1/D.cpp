#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T;
    cin >> T;
    while (T--)
    {
        ll N, K;
        cin >> N >> K;
        vector<ll> p(N + 1), q(N + 1);
        for (ll i = 1; i <= N; i++)
            cin >> p[i];
        for (ll i = 1; i <= N; i++)
            cin >> q[i];

        vector<ll> cyc_id(N + 1, -1), pos(N + 1);
        vector<vector<ll>> cycles;
        for (ll i = 1; i <= N; i++)
        {
            if (cyc_id[i] != -1)
                continue;
            ll id = cycles.size(), curr = i;
            vector<ll> cyc;
            while (cyc_id[curr] == -1)
            {
                cyc_id[curr] = id;
                pos[curr] = cyc.size();
                cyc.push_back(curr);
                curr = p[curr];
            }
            cycles.push_back(cyc);
        }

        vector<vector<ll>> cnt(N + 1);
        for (auto cyc : cycles)
        {
            ll L = cyc.size();
            if (cnt[L].empty())
                cnt[L].assign(L, 0);
            for (auto i : cyc)
            {
                ll t = q[i];
                if (cyc_id[t] != cyc_id[i])
                    continue;
                ll d = pos[t] - pos[i];
                if (d < 0)
                    d += L;
                cnt[L][d]++;
            }
        }

        vector<ll> ans(K + 1, 0);
        for (ll L = 1; L <= N; L++)
        {
            if (cnt[L].empty())
                continue;
            if (L > K)
            {
                for (ll k = 1; k <= K; k++)
                    ans[k] += cnt[L][k];
            }
            else
            {
                for (ll d = 1; d < L; d++)
                {
                    if (cnt[L][d] == 0)
                        continue;
                    for (ll k = d; k <= K; k += L)
                        ans[k] += cnt[L][d];
                }
                if (cnt[L][0] != 0)
                {
                    for (ll k = L; k <= K; k += L)
                        ans[k] += cnt[L][0];
                }
            }
        }
        cout << *max_element(ans.begin(), ans.end()) << endl;
    }
    return 0;
}