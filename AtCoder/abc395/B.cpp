#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main()
{
    int N;
    cin >> N;

    vector<vector<int>> grid(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        int j = N + 1 - i;

        if (i <= j)
        {
            int color = (i % 2 == 1) ? 1 : 2;

            for (int row = i; row <= j; row++)
            {
                for (int col = i; col <= j; col++)
                {
                    grid[row][col] = color;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (grid[i][j] == 1)
            {
                cout << '#';
            }
            else
            {
                cout << '.';
            }
        }
        cout << endl;
    }

    return 0;
}