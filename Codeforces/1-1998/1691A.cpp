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

        int evenCount = 0;
        int oddCount = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
                evenCount++;
            else
                oddCount++;
        }

        cout << min(evenCount, oddCount) << endl;
    }
    return 0;
}
