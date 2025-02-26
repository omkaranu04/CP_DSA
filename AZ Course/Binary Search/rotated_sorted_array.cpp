#include <bits/stdc++.h>
using namespace std;
int check(vector<int> a, int mid)
{
    if (a[mid] < a[0])
        return 1;
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int low = 0;
        int high = n - 1;
        int ans = 0;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (check(a, mid) == 1)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        cout << ans << endl;
    }
}