#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
using matrix = vector<vector<ll>>;
matrix matmul(matrix &A, matrix &B)
{
    ll n = A.size();
    matrix C(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++)
    {
        for (ll k = 0; k < n; k++)
        {
            if (A[i][k])
            {
                for (ll j = 0; j < n; j++)
                {
                    C[i][j] += (A[i][k] * B[k][j]) % MOD;
                    if (C[i][j] >= MOD)
                        C[i][j] -= MOD;
                }
            }
        }
    }
    return C;
}
matrix matpow(matrix a, ll b)
{
    ll n = a.size();
    matrix res(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++)
        res[i][i] = 1;
    while (b)
    {
        if (b & 1)
            res = matmul(res, a);
        a = matmul(a, a);
        b >>= 1;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, K;
    cin >> N >> K;
    matrix a(N, vector<ll>(N));
    for (ll i = 1; i <= N; i++)
    {
        for (ll j = 1; j <= N; j++)
            cin >> a[i - 1][j - 1];
    }

    matrix ak = matpow(a, K);
    ll ans = 0;
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
        {
            ans += ak[i][j];
            if (ans >= MOD)
                ans -= MOD;
        }
    }
    cout << ans;
    return 0;
}