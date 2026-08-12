#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<char> a(n + 1), b(m + 1);
        for (int i = 1; i < n + 1; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i < m + 1; i++)
        {
            cin >> b[i];
        }
        vector<int> dp(m + 1);
        if (a[1] == b[1])
            dp[1] = 1;
        else
            dp[1] = 0;
        for (int i = 2; i < m + 1; i++)
        {
            if (dp[i - 1] != n && b[i] == a[dp[i - 1] + 1])
                dp[i] = dp[i - 1] + 1;
            else
                dp[i] = dp[i - 1];
        }
        cout << dp[m] << endl;
    }
    return 0;
}