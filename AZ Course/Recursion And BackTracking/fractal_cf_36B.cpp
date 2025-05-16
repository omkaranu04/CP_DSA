#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<string> model;

vector<string> build(int level)
{
    if (level == 0)
        return {"."};

    vector<string> prev = build(level - 1);
    int size_prev = prev.size();
    int new_size = size_prev * n;
    vector<string> result(new_size, string(new_size, '.'));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            char ch = model[i][j];
            for (int x = 0; x < size_prev; ++x)
            {
                for (int y = 0; y < size_prev; ++y)
                {
                    int nx = i * size_prev + x;
                    int ny = j * size_prev + y;
                    if (ch == '*')
                        result[nx][ny] = '*';
                    else
                        result[nx][ny] = prev[x][y];
                }
            }
        }
    }

    return result;
}

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    cin >> n >> k;
    model.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> model[i];

    vector<string> answer = build(k);
    for (auto &row : answer)
        cout << row << '\n';

    return 0;
}
