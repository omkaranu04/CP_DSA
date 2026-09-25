#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, M, K, X, Y;
    cin >> N >> M >> K >> X >> Y;
    vector<ll> A(N), B(M);
    for (auto &x : A)
        cin >> x;
    for (auto &x : B)
        cin >> x;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<ll> psA(N + 1, 0), psB(M + 1, 0);
    for (ll i = 0; i < N; i++)
        psA[i + 1] = psA[i] + A[i];
    for (ll i = 0; i < M; i++)
        psB[i + 1] = psB[i] + B[i];

    vector<ll> psK(M + 1, 0);
    for (ll i = 0; i < M; i++)
        psK[i + 1] = psK[i] + ((B[i] + K - 1) / K);

    ll ans = 0;
    for (ll d = 0; d <= M; d++)
    {
        if (psK[d] > Y)
            break;
        ll rem = X + Y * K - psB[d];
        if (rem < 0)
            continue;
        ll c = upper_bound(psA.begin(), psA.end(), rem) - psA.begin();
        ans = max(ans, d + c - 1);
    }
    cout << ans << endl;
    return 0;
}