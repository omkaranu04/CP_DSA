#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int prev_check = 0, ahead = 0, ans = 1;
    map<ll, ll> freq;
    while (ahead < n)
    {
        if (prev_check < n && freq[a[prev_check]] == 0)
        {
            freq[a[prev_check]]++;
            prev_check++;
        }
        else
        {
            freq[a[ahead]]--;
            ahead++;
        }
        ans = max(ans, prev_check - ahead);
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