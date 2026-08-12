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
        if (n == 1)
            cout << 1 << endl;
        else if (n == 2)
            cout << -1 << endl;
        else
        {
            int num = 1;
            int a[n + 1][n + 1];
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if ((i + j) % 2 == 0)
                    {
                        a[i][j] = num;
                        num++;
                    }
                }
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if ((i + j) % 2 != 0)
                    {
                        a[i][j] = num;
                        num++;
                    }
                }
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}