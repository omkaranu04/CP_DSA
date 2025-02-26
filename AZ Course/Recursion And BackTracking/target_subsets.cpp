#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> generate(vector<ll> &a, ll x, ll n)
{
    vector<ll> sums;
    for (int i = 0; i < (1 << n); i++)
    {
        ll sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                sum += a[j];
            }
        }
        sums.push_back(sum);
    }
    return sums;
}
void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> divided_arr[2];
    for (int i = 0; i < n; i++)
    {
        divided_arr[i % 2].push_back(a[i]);
    }
    vector<ll> sums1, sums2;
    sums1 = generate(divided_arr[0], x, divided_arr[0].size());
    sums2 = generate(divided_arr[1], x, divided_arr[1].size());
    sort(sums1.begin(), sums1.end());
    sort(sums2.begin(), sums2.end());
    ll ans = 0;
    for (auto i : sums1)
    {
        ans += upper_bound(sums2.begin(), sums2.end(), x - i) - sums2.begin();
    }
    cout << ans << "\n";
    return;
}
int main()
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