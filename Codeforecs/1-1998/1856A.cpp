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
            cin >> a[i];
        }
        int maxi = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
                maxi = max(maxi, a[i]);
        }
        cout << maxi << endl;
    }
    return 0;
}