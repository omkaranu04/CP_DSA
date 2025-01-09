#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool check(vector<ll> &a, ll mid, ll median)
{
    ll num_subs = 0;
    ll curr_sum = 0;
    ll i = 0;
    ll j = 0;
    while (j < a.size())
    {
        curr_sum += a[j];
        while (i <= j && curr_sum > mid)
        {
            curr_sum -= a[i];
            i++;
        }
        num_subs += (j - i + 1);
        j++;
    }
    return num_subs >= median;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll low = 0, high = 0;
    ll ans = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        high += a[i];
    }
    ll x = (n * (n + 1)) / 2;
    ll median = (x + 1) / 2;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (check(a, mid, median))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
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