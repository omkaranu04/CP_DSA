#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    vector<string> grid(H);
    for (int i = 0; i < H; i++)
    {
        cin >> grid[i];
    }

    int minRow = numeric_limits<int>::max();
    int maxRow = numeric_limits<int>::min();
    int minCol = numeric_limits<int>::max();
    int maxCol = numeric_limits<int>::min();

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (grid[i][j] == '#')
            {
                minRow = min(minRow, i);
                maxRow = max(maxRow, i);
                minCol = min(minCol, j);
                maxCol = max(maxCol, j);
            }
        }
    }

    for (int i = minRow; i <= maxRow; i++)
    {
        for (int j = minCol; j <= maxCol; j++)
        {
            if (grid[i][j] == '.')
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}