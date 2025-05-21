#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const int INF = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> P(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> P[i];
    }

    vector<int> B(N);
    for (int i = 1; i < N; i++)
    {
        B[i] = (P[i + 1] > P[i] ? +1 : -1);
    }

    vector<int> peaks, valleys;
    vector<int> T(N, 0);
    for (int i = 2; i < N; i++)
    {
        if (B[i - 1] == +1 && B[i] == -1)
        {
            T[i] = +1;
            peaks.push_back(i);
        }
        else if (B[i - 1] == -1 && B[i] == +1)
        {
            T[i] = -1;
            valleys.push_back(i);
        }
    }

    vector<int> nextAny(N + 2, INF);
    for (int i = N; i >= 1; i--)
    {
        nextAny[i] = (T[i] != 0 ? i : nextAny[i + 1]);
    }
    nextAny[N + 1] = INF;

    ll answer = 0;

    for (int l = 1; l < N; l++)
    {
        if (B[l] != +1)
            continue;

        auto pit = lower_bound(peaks.begin(), peaks.end(), l + 1);
        auto vit = lower_bound(valleys.begin(), valleys.end(), l + 1);
        if (pit == peaks.end() || vit == valleys.end())
            continue;

        int p = *pit;
        int v = *vit;

        int first, second;
        if (p < v)
        {
            first = p;
            auto vit2 = lower_bound(valleys.begin(), valleys.end(), p + 1);
            if (vit2 == valleys.end())
                continue;
            second = *vit2;
        }
        else
        {
            first = v;
            auto pit2 = lower_bound(peaks.begin(), peaks.end(), v + 1);
            if (pit2 == peaks.end())
                continue;
            second = *pit2;
        }

        int j = nextAny[second + 1];
        if (j >= N)
            j = N;
        answer += (j - second);
    }

    cout << answer << "\n";
    return 0;
}