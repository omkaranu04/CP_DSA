#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<ll> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        sort(A.begin(), A.end());

        ll ans = N;
        for (int i = 0; i < N; i++)
        {
            ll x = A[i];
            ll remaining = N - (i + 1);
            ans = min(ans, x + remaining);
        }

        cout << ans << "\n";
    }

    return 0;
}
