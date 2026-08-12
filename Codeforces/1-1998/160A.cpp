#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, sum = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    reverse(a, a + n);
    int taken = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        if (taken > sum / 2)
            break;
        else
        {
            taken += a[i];
        }
    }

    cout << i << endl;
    return 0;
}