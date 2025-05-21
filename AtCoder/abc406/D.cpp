#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, N;
    cin >> H >> W >> N;

    unordered_map<int, unordered_set<int>> row_map;
    unordered_map<int, unordered_set<int>> col_map;

    for (int i = 0; i < N; ++i)
    {
        int x, y;
        cin >> x >> y;
        row_map[x].insert(y);
        col_map[y].insert(x);
    }

    int Q;
    cin >> Q;
    while (Q--)
    {
        int type, idx;
        cin >> type >> idx;

        if (type == 1)
        {
            int count = row_map[idx].size();
            cout << count << '\n';

            for (int y : row_map[idx])
            {
                col_map[y].erase(idx);
                if (col_map[y].empty())
                {
                    col_map.erase(y);
                }
            }
            row_map.erase(idx);
        }
        else
        {
            int count = col_map[idx].size();
            cout << count << '\n';

            for (int x : col_map[idx])
            {
                row_map[x].erase(idx);
                if (row_map[x].empty())
                {
                    row_map.erase(x);
                }
            }
            col_map.erase(idx);
        }
    }

    return 0;
}
