#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool found = false;
        for (int i = 1; i < n - 1; i++)
        {
            if (a[i] != a[i - 1] && a[i] != a[i + 1])
            {
                cout << i + 1 << endl;
                found = true;
            }
        }
        if (found == false)
        {
            if (a[0] != a[1])
            {
                cout << 1 << endl;
            }
            else
            {
                cout << n << endl;
            }
        }
    }

    return 0;
}
