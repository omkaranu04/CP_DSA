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
        int a[n], b[n - 1];
        for (int i = 0; i < n - 1; i++)
        {
            cin >> b[i];
        }
        a[0] = b[0];
        a[n - 1] = b[n - 2];
        for (int i = 1; i < n - 1; i++)
        {
            a[i] = min(b[i], b[i - 1]);
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}