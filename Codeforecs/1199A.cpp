#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        bool possible = true;
        for (int j = 1; j <= x && i - j >= 1; j++)
        {
            if (a[i - j] < a[i])
                possible = false;
        }
        for (int j = 1; j <= y && i + j <= n; j++)
        {
            if (a[i + j] < a[i])
                possible = false;
        }
        if (possible)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}