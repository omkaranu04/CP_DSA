#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll left = 0, right = 0;
    ll ans = 0;
    map<ll, ll> freq;
    ll curr_unique = 0;
    while (right < n)
    {
        freq[a[right]]++;
        if (freq[a[right]] == 1)
            curr_unique++;
        while (left <= right && curr_unique > k)
        {
            if (freq[a[left]] == 1)
                curr_unique--;
            freq[a[left]]--;
            left++;
        }
        ans += (right - left + 1);
        right++;
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