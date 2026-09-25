#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int LOG = 31;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> par(LOG, vector<int>(N + 1));
    for (int i = 1; i <= N; i++)
        cin >> par[0][i];
    for (int j = 1; j < LOG; j++)
        for (int i = 1; i <= N; i++)
            par[j][i] = par[j - 1][par[j - 1][i]];

    while (Q--)
    {
        int x;
        ll k;
        cin >> x >> k;

        for (int j = 0; j < LOG; j++)
        {
            if (k & (1LL << j))
                x = par[j][x];
        }
        cout << x << '\n';
    }

    return 0;
}