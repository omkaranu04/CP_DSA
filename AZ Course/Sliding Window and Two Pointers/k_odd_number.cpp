#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, k, d;
    cin >> n >> k >> d;
    vector<ll> a(n + 1), ps(n + 1);
    ps[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }
    ll left = 1, right = 1;
    ll curr_count = 0;
    multiset<ll> curr_sums_possible;
    curr_sums_possible.insert(0);
    ll ans = LLONG_MIN;
    while (right < n + 1)
    {
        if (abs(a[right] % 2))
            curr_count++;
        if (curr_count > k)
        {
            while (left <= right)
            {
                curr_sums_possible.erase(curr_sums_possible.find(ps[left - 1]));
                if (abs(a[left] % 2))
                {
                    left++;
                    curr_count--;
                    break;
                }
                left++;
            }
        }
        if (!curr_sums_possible.empty())
        {
            auto it = curr_sums_possible.lower_bound(ps[right] - d);
            if (it != curr_sums_possible.end())
            {
                ans = max(ans, ps[right] - (*it));
            }
        }
        curr_sums_possible.insert(ps[right]);
        right++;
    }
    if (ans == LLONG_MIN)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    else
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