#include <iostream>
#include <vector>
using namespace std;
#define ll long long int

ll get_min_pair(int a, int b)
{
    return min(a, b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int N, Q;
        cin >> N >> Q;

        vector<int> A(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> A[i];
        }

        long long score = 0;
        for (int i = 0; i < N - 1; ++i)
        {
            score += get_min_pair(A[i], A[i + 1]);
        }

        while (Q--)
        {
            int i, X;
            cin >> i >> X;
            --i;

            if (i > 0)
                score -= get_min_pair(A[i - 1], A[i]);
            if (i < N - 1)
                score -= get_min_pair(A[i], A[i + 1]);

            A[i] = X;

            if (i > 0)
                score += get_min_pair(A[i - 1], A[i]);
            if (i < N - 1)
                score += get_min_pair(A[i], A[i + 1]);

            cout << score << '\n';
        }
    }

    return 0;
}