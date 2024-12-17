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
        ll n, m;
        cin >> n >> m;
        vector<vector<char>> board(n, vector<char>(m));
        vector<ll> row(n, 0);
        vector<ll> col(m, 0);
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> board[i][j];
                if (board[i][j] == '#')
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        ll c1 = 1, c2 = 1;

        if (n > 1)
        {
            for (ll i = 1; i < n - 1; i++)
            {
                if (row[i] >= row[c1 - 1])
                {
                    c1 = i + 1;
                }
            }
        }

        if (m > 1)
        {
            for (ll j = 1; j < m - 1; j++)
            {
                if (col[j] >= col[c2 - 1])
                {
                    c2 = j + 1;
                }
            }
        }
        if (row[n - 1] >= row[c1 - 1])
            c1 = n;
        if (col[m - 1] >= col[c2 - 1])
            c2 = m;

        cout << c1 << " " << c2 << endl;
        }
    return 0;
}