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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int flag = 1;
        for (int i = 0; i < n - 2; i++)
        {
            if (a[i] < 0)
            {
                flag = 0;
            }
            int del = a[i];
            a[i] -= del;
            a[i + 1] -= 2 * del;
            a[i + 2] -= del;
        }
        if (a[n - 1] != 0 || a[n - 2] != 0 || flag == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}