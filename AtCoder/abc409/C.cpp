#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, L;
    cin >> N >> L;
    vector<ll> d(N);
    for (ll i = 1; i <= N - 1; i++)
        cin >> d[i];
    vector<ll> ps(N, 0);
    ps[0] = 0;
    for (ll i = 1; i < N; i++)
        ps[i] = (ps[i - 1] + d[i]) % L;
    if (L % 3 != 0)
        cout << 0 << endl;
    else
    {
        ll shft = L / 3;
        map<ll, ll> mp;
        for (auto x : ps)
            mp[x]++;
        ll ans = 0;
        for (auto &[p, c] : mp)
        {
            ll pp = (p + shft) % L;
            ll cc = (p + 2 * shft) % L;
            auto it1 = mp.find(pp);
            if (it1 == mp.end())
                continue;
            auto it2 = mp.find(cc);
            if (it2 == mp.end())
                continue;
            ans += (c * it1->second * it2->second);
        }
        cout << ans / 3 << endl;
    }
    return 0;
}