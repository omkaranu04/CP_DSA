#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool check(vector<ll> &x, int mid, int k, int n)
{
    ll prev_sitted = x[0];
    ll sitted = 1;
    for (int i = 1; i < n; i++)
    {
        if (prev_sitted + mid <= x[i])
        {
            sitted++;
            prev_sitted = x[i];
        }
    }
    return sitted >= k;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    int low = 1;
    int high = x[n - 1] - x[0];
    int ans = low;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        if (check(x, mid, k, n))
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