#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c, d;
        cin >> n >> c >> d;
        vector<int> a(n * n);
        for (int i = 0; i < n * n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> b(n * n);
        b[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            b[i] = b[i - 1] + d;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                b[i * n + j] = b[(i - 1) * n + j] + c;
            }
        }
        sort(b.begin(), b.end());
        if (a == b)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}