#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    int lb = (n + 1) / 2;
    for (int i = lb; i <= n; i++)
    {
        if (i % m == 0)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}