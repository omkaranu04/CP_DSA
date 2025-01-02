#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<vector<char>> a(n + 1, vector<char>(n + 1));
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<char>> b(n + 1, vector<char>(n + 1));
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            ll c = min({i, j, n - i + 1, n - j + 1});
            c = c % 4;
            ll ni = i, nj = j;
            while (c)
            {
                ll ti = nj;
                ll tj = n - ni + 1;
                ni = ti;
                nj = tj;
                c--;
            }
            b[ni][nj] = a[i][j];
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cout << b[i][j];
        }
        cout << endl;
    }
    return 0;
}