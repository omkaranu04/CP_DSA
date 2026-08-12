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
        vector<int> a(n);
        int count = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 0)
                count++;
            else
            {
                ans = max(ans, count);
                count = 0;
            }
        }
        cout << max(ans, count) << endl;
    }
    return 0;
}