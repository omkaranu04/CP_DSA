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
        int m = (n * (n - 1)) / 2;
        int b[m];
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        sort(b, b + m);
        for (int i = 0; i < m; i += --n)
        {
            cout << b[i] << " ";
        }
        cout << 1000000000 << " ";
    }
    return 0;
}