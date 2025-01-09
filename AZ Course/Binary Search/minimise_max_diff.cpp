#include <bits/stdc++.h>
using namespace std;
#define ll int
bool check(vector<int> a, int n, int mid, int k)
{
    int req = 0;
    for (int i = 1; i < n; i++)
    {
        req += (a[i] - a[i - 1] + mid - 1) / mid - 1;
    }
    return req <= k;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int maxgap = 0;
    for (int i = 1; i < n; i++)
    {
        maxgap = max(maxgap, a[i] - a[i - 1]);
    }
    int low = 1, high = 1e9;
    int ans = high;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(a, n, mid, k))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}