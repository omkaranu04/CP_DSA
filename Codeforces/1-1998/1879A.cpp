#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int s[n], e[n];
        for (int i = 0; i < n; i++)
        {
            cin >> s[i] >> e[i];
        }
        bool win = true;
        for (int i = 1; i < n; i++)
        {
            if (s[i] >= s[0] && e[i] >= e[0])
                win = false;
        }
        if (win)
            cout << s[0] << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}