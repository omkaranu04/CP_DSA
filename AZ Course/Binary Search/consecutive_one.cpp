#include <bits/stdc++.h>
using namespace std;
#define ll int
bool check(vector<int> a, int n, int mid, int k)
{
    int cnt0 = 0;
    for (int i = 0; i < mid; i++)
    {
        if (!a[i])
            cnt0++;
    }
    if (cnt0 <= k)
        return true;
    for (int i = mid; i < n; i++)
    {
        if (a[i - mid] == 0)
            cnt0--;
        if (a[i] == 0)
            cnt0++;
        if (cnt0 <= k)
            return true;
    }
    return false;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> ps(n + 1);
    ps[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int low = k, high = n;
    int ans = k;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(a, n, mid, k))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << ans << "\n";
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