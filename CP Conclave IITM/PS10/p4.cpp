#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, k, q;
        cin >> n >> k >> q;
        long long int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > q)
                a[i] = 0;
            else
                a[i] = 1;
        }
        long long int ans = 0, len = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
            {
                len++;
            }
            else
            {
                if (len >= k)
                {
                    ans += (len - k + 1) * (len - k + 2) / 2;
                }
                len = 0;
            }
        }
        if (len >= k)
        {
            ans += (len - k + 1) * (len - k + 2) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}