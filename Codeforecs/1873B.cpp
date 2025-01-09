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
        long long int prod = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        a[0] += 1;
        for (int i = 0; i < n; i++)
        {
            prod *= a[i];
        }
        cout << prod << endl;
    }
    return 0;
}
