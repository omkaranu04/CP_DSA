#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<ll> C(N);
    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
    }

    vector<vector<int>> zoo_animals(N);
    for (int ani = 0; ani < M; ani++)
    {
        int K;
        cin >> K;
        while (K--)
        {
            int z;
            cin >> z;
            zoo_animals[z - 1].push_back(ani);
        }
    }

    ll ans = LLONG_MAX;
    int total = 1;
    for (int i = 0; i < N; i++)
        total *= 3;
    vector<int> visits(N);

    for (int mask = 0; mask < total; mask++)
    {
        int t = mask;
        ll cost = 0;
        for (int j = 0; j < N; j++)
        {
            visits[j] = t % 3;
            t /= 3;
            cost += visits[j] * C[j];
        }
        if (cost >= ans)
            continue;

        vector<int> seen(M, 0);
        for (int j = 0; j < N; j++)
        {
            if (visits[j] > 0)
            {
                for (int ani : zoo_animals[j])
                {
                    seen[ani] += visits[j];
                }
            }
        }
        bool ok = true;
        for (int ani = 0; ani < M; ani++)
        {
            if (seen[ani] < 2)
            {
                ok = false;
                break;
            }
        }
        if (ok)
            ans = cost;
    }

    cout << ans << "\n";
    return 0;
}