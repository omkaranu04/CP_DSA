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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = i + 1;
        }
        if (n % 2 == 0)
        {
            for (int i = 1; i <= n - 1; i += 2)
            {
                cout << a[i] << " " << a[i - 1] << " ";
            }
        }
        else
        {
            cout << a[2] << " " << a[0] << " " << a[1] << " ";
            for (int i = 4; i <= n - 1; i += 2)
            {
                cout << a[i] << " " << a[i - 1] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}