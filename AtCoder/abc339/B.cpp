#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll h, w, n;
    cin >> h >> w >> n;

    vector<vector<char>> grid(h + 1, vector<char>(w + 1, '.'));

    ll x = 1, y = 1, d = 0;

    while (n--)
    {
        if (grid[x][y] == '.')
        {
            grid[x][y] = '#';
            d = (d + 1) % 4;
        }
        else
        {
            grid[x][y] = '.';
            d = (d + 3) % 4;
        }

        if (d == 0)
            x -= 1;
        else if (d == 1)
            y += 1;
        else if (d == 2)
            x += 1;
        else
            y -= 1;

        if (x < 1)
            x = h;
        else if (x > h)
            x = 1;
        if (y < 1)
            y = w;
        else if (y > w)
            y = 1;
    }

    for (ll i = 1; i <= h; i++)
    {
        for (ll j = 1; j <= w; j++)
        {
            cout << grid[i][j];
        }
        cout << "\n";
    }

    return 0;
}
