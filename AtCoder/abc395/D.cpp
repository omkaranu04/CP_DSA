#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<int> perm(N + 1), inv(N + 1), pos(N + 1);

    for (int i = 1; i <= N; i++)
    {
        perm[i] = i;
        inv[i] = i;
        pos[i] = i;
    }

    while (Q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int a, b;
            cin >> a >> b;
            pos[a] = inv[b];
        }
        else if (type == 2)
        {
            int a, b;
            cin >> a >> b;

            int x = inv[a], y = inv[b];
            swap(perm[x], perm[y]);
            swap(inv[a], inv[b]);
        }
        else if (type == 3)
        {
            int a;
            cin >> a;
            cout << perm[pos[a]] << "\n";
        }
    }

    return 0;
}