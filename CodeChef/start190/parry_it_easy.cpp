#include <bits/stdc++.h>
using namespace std;

int maxParries(int N, int X, const vector<int> &A, const vector<int> &B)
{
    int parries = 0;
    for (int i = 0; i < N; ++i)
    {
        if (X < A[i])
        {
            return -1;
        }
        else if (X >= B[i])
        {

            if (X - 1 >= (i + 1 < N ? *max_element(A.begin() + i + 1, A.end()) : 0))
            {
                X -= 1;
                ++parries;
            }
        }
    }
    return parries;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int N, X;
        cin >> N >> X;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];
        for (int i = 0; i < N; ++i)
            cin >> B[i];

        vector<int> maxA(N);
        maxA[N - 1] = A[N - 1];
        for (int i = N - 2; i >= 0; --i)
            maxA[i] = max(A[i], maxA[i + 1]);

        int parries = 0;
        for (int i = 0; i < N; ++i)
        {
            if (X < A[i])
            {
                parries = -1;
                break;
            }
            else if (X >= B[i])
            {
                int maxFutureA = (i + 1 < N ? maxA[i + 1] : 0);
                if (X - 1 >= maxFutureA)
                {
                    X -= 1;
                    ++parries;
                }
            }
            // no option to do
        }

        cout << parries << '\n';
    }

    return 0;
}