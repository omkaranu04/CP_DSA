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
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        vector<ll> B(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int i = 0; i < N; i++)
            cin >> B[i];

        vector<pair<int, int>> order(N);
        for (int i = 0; i < N; i++)
            order[i] = {A[i], i};
        sort(order.begin(), order.end());

        vector<ll> ans(N);
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll sum = 0;

        for (auto &pr : order)
        {
            int idx = pr.second;
            ans[idx] = sum;

            if (K > 0)
            {
                if ((int)pq.size() < K)
                {
                    pq.push(B[idx]);
                    sum += B[idx];
                }
                else if (B[idx] > pq.top())
                {
                    sum += B[idx] - pq.top();
                    pq.pop();
                    pq.push(B[idx]);
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            cout << ans[i] << (i + 1 < N ? ' ' : '\n');
        }
    }

    return 0;
}
