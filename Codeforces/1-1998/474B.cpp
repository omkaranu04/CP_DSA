#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, sum = 0;
    cin >> n;
    int a[n], count[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        count[i] = sum;
    }
    int index = 0, worms[sum + 1];
    worms[0] = 0;
    for (int i = 1; i <= sum; i++)
    {
        if (i > count[index])
            index++;
        worms[i] = index + 1;
    }
    int m;
    cin >> m;
    int q[m], output[m];
    for (int i = 0; i < m; i++)
    {
        cin >> q[i];
        output[i] = worms[q[i]];
    }
    for (int i = 0; i < m; i++)
    {
        cout << output[i] << endl;
    }

    return 0;
}
