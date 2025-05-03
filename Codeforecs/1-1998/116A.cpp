#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    int max = b[0];
    int currpass = b[0];
    for (int i = 1; i < n; i++)
    {
        currpass = currpass - a[i] + b[i];
        if (currpass > max)
            max = currpass;
    }
    cout << max << endl;
    return 0;
}
