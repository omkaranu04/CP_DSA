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
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (a[0] == 1)
            b[0] = 2;
        else
            b[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (b[i - 1] + 1 == a[i])
                b[i] = b[i - 1] + 2;
            else
                b[i] = b[i - 1] + 1;
        }
        cout << b[n - 1] << endl;
    }
    return 0;
}