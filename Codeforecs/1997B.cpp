#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<string> grid(2);
        cin >> grid[0];
        cin >> grid[1];

        ll cnt = 0;

        for (int i = 1; i < n - 1; i++)
        {
            bool s = true;
            s &= (grid[0][i] == '.' && grid[1][i] == '.');
            s &= (grid[0][i - 1] != grid[1][i - 1]);
            s &= (grid[0][i + 1] != grid[1][i + 1]);
            s &= (grid[0][i - 1] == grid[0][i + 1]);

            cnt += s;
        }

        cout << cnt << endl;
    }
    return 0;
}