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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        int count = 0;
        for (int i = 0; i < n * n; i++)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] > b[i])
                {
                    a[n - 1] = b[i];
                    sort(a.begin(), a.end());
                    count++;
                    continue;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}