#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> freq(1000001, 0);
void solve()
{
    ll n, d;
    cin >> n >> d;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll right = 0, ans = d;
    ll curr_unique = 0;
    while (right < n)
    {
        freq[a[right]]++;
        if (freq[a[right]] == 1)
            curr_unique++;
        if (right >= d)
        {
            if (freq[a[right - d]] == 1)
                curr_unique--;
            freq[a[right - d]]--;
        }
        if (right + 1 >= d)
            ans = min(ans, curr_unique);
        right++;
    }
    cout << ans << "\n";
    for (int i = n - d; i < n; i++)
        freq[a[i]]--;
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