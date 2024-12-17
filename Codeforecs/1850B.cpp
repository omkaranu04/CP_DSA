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
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
        }
        int maxqual = -1;
        int winner;
        for (int i = 0; i < n; i++)
        {
            if (a[i] <= 10 && b[i] > maxqual)
            {
                maxqual = b[i];
                winner = i + 1;
            }
        }
        cout << winner << endl;
    }
    return 0;
}