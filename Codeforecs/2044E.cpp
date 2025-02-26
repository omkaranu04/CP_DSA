#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> compute_powers_of_k(ll k, ll max_limit)
{
    vector<ll> powers_of_k;
    ll temp = 1;
    powers_of_k.push_back(temp);
    while (temp <= max_limit / k)
    {
        temp *= k;
        powers_of_k.push_back(temp);
    }
    return powers_of_k;
}
void solve()
{
    ll k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    vector<ll> powers_of_k = compute_powers_of_k(k, 1e9);

    ll ans = 0;
    for (auto i : powers_of_k)
    {
        // smallest x that satisfies y = i * x
        ll low = l1, high = r1;
        ll ans1 = -1;
        while (low <= high)
        {
            ll mid = (low + high) / 2;
            if (mid <= r2 / i)
            {
                ans1 = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        // largest x that satisfies y = i * x
        low = l1, high = r1;
        ll ans2 = -1;
        while (low <= high)
        {
            ll mid = (low + high) / 2;
            if (mid >= (l2 + i - 1) / i)
            {
                ans2 = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        if (ans1 != -1 && ans2 != -1)
        {
            ans += max(0LL, ans1 - ans2 + 1);
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