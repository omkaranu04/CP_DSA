#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    char cross[n][n];
    set<char> diag, nondiag;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cross[i][j];
            if (i == j || i == n - j - 1)
                diag.insert(cross[i][j]);
            else
                nondiag.insert(cross[i][j]);
        }
    }
    auto it1 = diag.begin(), it2 = nondiag.begin();
    if (size(diag) == 1 && size(nondiag) == 1 && (*it1) != (*it2))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}