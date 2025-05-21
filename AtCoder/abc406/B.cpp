#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int K;
    cin >> N >> K;
    vector<unsigned long long> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    unsigned long long limit = 1;
    for (int i = 0; i < K; i++)
    {
        limit *= 10ULL;
    }

    unsigned long long curr = 1;
    for (int i = 0; i < N; i++)
    {
        __uint128_t prod = (__uint128_t)curr * A[i];
        if (prod >= limit)
        {
            curr = 1;
        }
        else
        {
            curr = (unsigned long long)prod;
        }
    }

    cout << curr << "\n";
    return 0;
}
