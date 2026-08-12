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
        int maxi = INT_MIN;
        for (int i = n; i > 0; i--)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (i % a[j] == 0)
                    count++;
            }
            maxi = max(maxi, count);
        }
        cout << maxi << endl;
    }
    return 0;
}