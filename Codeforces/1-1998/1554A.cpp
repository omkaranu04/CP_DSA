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
        long long int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long long int max = INT_MIN;
        for (int i = 0; i <= n - 2; i++)
        {
            if (a[i] * a[i + 1] > max)
                max = a[i] * a[i + 1];
        }
        cout << max << endl;
    }
    return 0;
}