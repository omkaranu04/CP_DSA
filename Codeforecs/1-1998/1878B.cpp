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
        a[0] = 1;
        a[1] = 3;
        for (int i = 2; i < n; i++)
        {
            a[i] = i + 2;
        }
        for (int i = 2; i <= n - 1; i++)
        {
            while (((3 * a[i]) % (a[i - 1] + a[i - 2]) == 0) || (a[i] <= a[i - 1]))
            {
                a[i]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}