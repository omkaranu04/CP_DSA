#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        long long int ans = 0, currmin = 1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= currmin)
            {
                ans += a[i] - currmin;
                currmin++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
