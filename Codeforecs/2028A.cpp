#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    ll n, a, b;
    cin >> n >> a >> b;

    string s;
    cin >> s;

    int x = 0, y = 0;

    for (int cycle = 0; cycle < 10000; cycle++)
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'N')
                y++;
            else if (s[i] == 'S')
                y--;
            else if (s[i] == 'E')
                x++;
            else if (s[i] == 'W')
                x--;

            if (x == a && y == b)
            {
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}