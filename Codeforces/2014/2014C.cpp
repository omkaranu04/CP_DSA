#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool check(vector<ll> &a, ll x, ll n, ll sum, ll max_elem)
{
    double mean = static_cast<double>(sum + x) / n;
    int unhappy_cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            if ((a[i] + x) < mean / 2.0)
                unhappy_cnt++;
        }
        else
        {
            if (a[i] < mean / 2.0)
            {
                unhappy_cnt++;
            }
        }
    }
    return (unhappy_cnt > (n / 2));
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    sort(a.begin(), a.end());
    ll low = 0, high = 1e18, ans = -1;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        if (check(a, mid, n, sum, a[n - 1]))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}