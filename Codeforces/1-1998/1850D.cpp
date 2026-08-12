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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int count = 1, ans = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] - a[i - 1] > k)
            {
                count = 1;
            }
            else
                count++;
            ans = max(count, ans);
        }
        cout << n - ans << endl;
    }
    return 0;
}