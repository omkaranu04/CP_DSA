#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll N, K;
vector<ll> A;
vector<vector<ll>> P;
ll modpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll t = modpow(a, b / 2);
    t = (t * t) % MOD;
    if (b % 2 == 0)
        return t;
    else
        return (t * a) % MOD;
}
vector<vector<ll>> matmul(vector<vector<ll>> A, vector<vector<ll>> B)
{
    ll n = A.size();
    vector<vector<ll>> C(n, vector<ll>(n));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            for (ll k = 0; k < n; k++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}
vector<vector<ll>> matpow(vector<vector<ll>> A, ll n)
{
    ll sz = A.size();
    vector<vector<ll>> t(sz, vector<ll>(sz));
    for (ll i = 0; i < sz; i++)
        t[i][i] = 1;
    while (n)
    {
        if (n & 1)
            t = matmul(t, A);
        A = matmul(A, A);
        n >>= 1;
    }
    return t;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    A.resize(N);
    for (auto &x : A)
        cin >> x;

    ll n0 = 0;
    for (auto &x : A)
        if (x == 0)
            n0++;
    ll n1 = N - n0;

    P.resize(n0 + 1, vector<ll>(n0 + 1, 0));
    for (ll i = 0; i <= n0; i++)
    {
        ll p1, p2, p3;
        p1 = (((i * (N - n0 - n0 + i)) % MOD * modpow(N * (N - 1), MOD - 2)) % MOD * 2LL) % MOD;
        // cout << "i: " << i << " " << "p1: " << p1 << endl;
        p2 = ((((n0 - i) * (n0 - i)) % MOD * modpow(N * (N - 1), MOD - 2)) % MOD * 2LL) % MOD;
        p3 = (1 - p1 - p2 + MOD + MOD) % MOD;
        if (i + 1 <= n0)
            P[i][i + 1] = p2;
        if (i - 1 >= 0)
            P[i][i - 1] = p1;
        P[i][i] = p3;
    }
    // for (ll i = 0; i <= n0; i++)
    // {
    //     for (ll j = 0; j <= n0; j++)
    //     {
    //         cout << P[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<vector<ll>> PK;
    PK = matpow(P, K);
    ll n0k = 0;
    for (ll i = 0; i < n0; i++)
        if (A[i] == 0)
            n0k++;
    ll ans = PK[n0k][n0];
    cout << ans << endl;
    return 0;
}