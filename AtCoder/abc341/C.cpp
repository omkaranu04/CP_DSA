#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll h, w, n;
    cin >> h >> w >> n;
    string t;
    cin >> t;
    vector<string> grid(h);
    for (ll i = 0; i < h; i++)
        cin >> grid[i];
    set<pair<ll, ll>> s;
    for (ll i = 0; i < h; i++)
    {
        for (ll j = 0; j < w; j++)
        {
            if (grid[i][j] == '#')
                continue;
            ll currx = i, curry = j, flag = 1;
            for (ll k = 0; k < n; k++)
            {
                if (t[k] == 'L')
                {
                    curry--;
                    if (curry < 0)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (t[k] == 'R')
                {
                    curry++;
                    if (curry >= w)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (t[k] == 'U')
                {
                    currx--;
                    if (currx < 0)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (t[k] == 'D')
                {
                    currx++;
                    if (currx >= h)
                    {
                        flag = 0;
                        break;
                    }
                }
                if (grid[currx][curry] == '#')
                {
                    flag = 0;
                    break;
                }
            }
            if (flag && grid[currx][curry] == '.')
                s.insert({currx, curry});
        }
    }
    cout << s.size() << endl;
    return 0;
}
