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
        string s;
        cin >> s;
        ll x = 0, y = 0;
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'L')
            {
                x -= 1;
                if (x == 1 && y == 1)
                    flag = true;
            }
            if (s[i] == 'R')
            {
                x += 1;
                if (x == 1 && y == 1)
                    flag = true;
            }
            if (s[i] == 'U')
            {
                y += 1;
                if (x == 1 && y == 1)
                    flag = true;
            }
            if (s[i] == 'D')
            {
                y -= 1;
                if (x == 1 && y == 1)
                    flag = true;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}