#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
ll power(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;
    ll temp = power(a, b / 2, mod) % mod;
    if (b % 2 == 0)
        return (temp * temp) % mod;
    else
        return (((temp * temp) % mod) * a) % mod;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, K;
    cin >> N >> K;
    vector<ll> P(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> P[i];
        P[i]--;
    }
    vector<ll> res(N);
    vector<bool> visited(N, false);

    for (int i = 0; i < N; i++)
    {
        if (visited[i])
            continue;

        vector<ll> cyc;
        ll curr = i;
        while (!visited[curr])
        {
            visited[curr] = true;
            cyc.push_back(curr);
            curr = P[curr];
        }

        ll cyc_size = cyc.size();
        ll x = power(2, K, cyc_size);
        for (int j = 0; j < cyc_size; j++)
        {
            ll temp = (j + x) % cyc_size;
            res[cyc[j]] = cyc[temp];
        }
    }
    for (auto i : res)
    {
        cout << i + 1 << " ";
    }
    return 0;
}