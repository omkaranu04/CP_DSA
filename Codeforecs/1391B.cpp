#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        char a[n + 1][m + 1];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i == n && a[i][j] == 'D')
                    count++;
                if (j == m && a[i][j] == 'R')
                    count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}