#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ct = 1;
    int max = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
            ct += 1;
        else
        {
            if (ct > max)
                max = ct;
            ct = 1;
        }
    }
    if (ct > max)
        max = ct;
    cout << max << endl;
    return 0;
}
