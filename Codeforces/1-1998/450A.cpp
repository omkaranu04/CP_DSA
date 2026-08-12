#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] % m == 0)
            a[i] = a[i] / m;
        else
            a[i] = a[i] / m + 1;
    }
    int max = a[0], maxINdex = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= max)
        {
            max = a[i];
            maxINdex = i;
        }
    }
    cout << maxINdex + 1 << endl;
    return 0;
}