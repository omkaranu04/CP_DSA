#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<string> grid(8);
    for (int i = 0; i < 8; i++)
    {
        cin >> grid[i];
    }
    vector<bool> row(8, false), col(8, false);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (grid[i][j] == '#')
            {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (!row[i] && !col[j])
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}