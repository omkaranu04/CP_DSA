#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long long int sum = 0, count1 = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            if (a[i] == 1)
                count1++;
        }
        if (sum >= count1 + n && n > 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}