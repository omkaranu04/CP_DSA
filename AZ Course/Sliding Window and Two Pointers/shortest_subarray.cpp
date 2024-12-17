#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> freq(1000001, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }
    ll all_distinct = 0;
    for (ll i = 0; i < 1000001; i++)
    {
        all_distinct += (freq[i] > 0);
        freq[i] = 0;
    }
    ll left = 0;
    ll right = 0;
    ll ans = n;
    ll curr_unique = 0;
    while (right < n)
    {
        freq[a[right]]++;
        if (freq[a[right]] == 1)
            curr_unique++;
        while (left <= right && curr_unique == all_distinct)
        {
            ans = min(ans, right - left + 1);
            if (freq[a[left]] == 1)
                curr_unique--;
            freq[a[left]]--;
            left++;
        }
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