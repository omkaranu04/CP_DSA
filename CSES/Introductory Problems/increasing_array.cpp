#include <bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    vector<int> curr_max(n + 1);
    curr_max[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (x[i - 1] > curr_max[i - 1])
        {
            curr_max[i] = x[i - 1];
        }
        else
        {
            curr_max[i] = curr_max[i - 1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += curr_max[i] - x[i - 1];
    }
    cout << ans << endl;
    return 0;
}