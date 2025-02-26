#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    long long int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long int n;
        cin >> n;
        long long int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        cout << max(a[0] * a[1], a[n - 1] * a[n - 2]) << endl;
    }
    return 0;
}
