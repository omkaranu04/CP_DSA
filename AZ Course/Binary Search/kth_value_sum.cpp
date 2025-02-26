#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> a, b;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    a.resize(n);
    b.resize(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    if (n > m)
    {
        swap(n, m);
        swap(a, b);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    // a and n becomes smaller entities
    int low = a[0] + b[0];
    int high = a[a.size() - 1] + b[b.size() - 1];
    int ans = low;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int suitable_pairs = 0;
        for (int i = 0; i < n; i++)
        {
            suitable_pairs += upper_bound(b.begin(), b.end(), mid - a[i]) - b.begin();
        }
        if (suitable_pairs >= k)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}