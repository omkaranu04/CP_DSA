#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool check(map<ll, ll> &freq, ll mid, ll k)
{
    ll balls = 0;
    for (auto i : freq)
    {
        balls += min(mid, i.second);
    }
    return balls >= k * mid;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<ll, ll> freq;
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }
    int low = 0;
    int high = n;
    int ans = low;
    while (low <= high)
    {
        // ll mid = (low + high) / 2;
        ll mid = low + (high - low) / 2;
        if (check(freq, mid, k))
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