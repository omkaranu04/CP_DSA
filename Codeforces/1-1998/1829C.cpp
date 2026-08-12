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
        vector<int> m(n);
        vector<string> ms(n);
        vector<int> a01, a10, a11;
        for (int i = 0; i < n; i++)
        {
            cin >> m[i] >> ms[i];
            if (ms[i] == "01")
                a01.push_back(m[i]);
            if (ms[i] == "10")
                a10.push_back(m[i]);
            if (ms[i] == "11")
                a11.push_back(m[i]);
        }
        sort(a01.begin(), a01.end());
        sort(a10.begin(), a10.end());
        sort(a11.begin(), a11.end());
        int ans = INT_MAX;

        if (!a11.empty())
        {
            ans = min(ans, a11[0]);
        }

        if (!a01.empty() && !a10.empty())
        {
            ans = min(ans, a01[0] + a10[0]);
        }

        if (ans == INT_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}