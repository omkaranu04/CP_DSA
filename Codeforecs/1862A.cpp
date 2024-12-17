#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int q;
    cin >> q;
    while (q--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> carpet(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> carpet[i];
        }
        string vika = "vika";
        int fnd = 0;
        for (int i = 0; i < m; ++i)
        {
            bool check = false;
            for (int j = 0; j < n; ++j)
            {
                if (carpet[j][i] == vika[fnd])
                {
                    check = true;
                }
            }
            if (check)
            {
                ++fnd;
                if (fnd == 4)
                {
                    break;
                }
            }
        }
        if (fnd == 4)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}