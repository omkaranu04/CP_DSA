#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int ans = 0;
        int d = n / k;
        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                if (i > d)
                    continue;
                if (i + j > m)
                    continue;
                if (i + (k - 1) * j < m)
                    continue;
                ans = max(ans, i - j);
            }
        }
        cout << ans << endl;
    }
    return 0;
}