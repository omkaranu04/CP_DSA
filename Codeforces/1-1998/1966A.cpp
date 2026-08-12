#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> c(n);
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        sort(c.begin(), c.end());
        int count = 1;
        bool flag = false;
        for (int i = 1; i < n; i++)
        {
            if (c[i] == c[i - 1])
            {
                count++;
                if (count >= k)
                    flag = true;
            }
            else
                count = 1;
        }
        if (flag)
            cout << k - 1 << endl;
        else
            cout << n << endl;
    }
    return 0;
}