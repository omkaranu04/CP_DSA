#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
const ll MAX = 200010;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> reco(MAX, 0);
    for (ll i = 0; i < n; i++)
    {
        ll l, r;
        cin >> l >> r;
        reco[l] += 1;
        reco[r + 1] -= 1;
    }
    for (ll i = 1; i < MAX; i++)
        reco[i] += reco[i - 1];
    vector<ll> adm(MAX, 0);
    for (ll i = 0; i < MAX; i++)
    {
        if (reco[i] >= k)
        {
            adm[i] += 1;
            if (i + 1 < MAX)
                adm[i + 1] -= 1;
        }
    }
    for (ll i = 1; i < MAX; i++)
        adm[i] += adm[i - 1];
    for (ll i = 1; i < MAX; i++)
        adm[i] += adm[i - 1];

    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        ll ans = adm[b] - adm[a - 1];
        cout << ans << endl;
    }
    return 0;
}