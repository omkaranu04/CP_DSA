#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

static const int64 P = 999999733;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int64 BASE = 1;
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        int64 K;
        cin >> N >> K;

        if (N == 2)
        {
            cout << K << ' ' << 2LL * K << "\n";
            continue;
        }
        if (K < N - 1)
        {
            cout << -1 << "\n";
            continue;
        }

        int64 x = K - (N - 2);
        vector<int64> A(N);

        A[0] = x;
        A[1] = 2 * x;
        for (int i = 1; i <= N - 2; i++)
            A[i + 1] = A[i] + 1;

        for (auto x : A)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}