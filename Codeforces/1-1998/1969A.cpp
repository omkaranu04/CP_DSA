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
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];
        }
        int flag = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[i] == j && p[j] == i)
                    flag = 1;
            }
        }
        if (flag)
            cout << 2 << endl;
        else
            cout << 3 << endl;
    }
    return 0;
}