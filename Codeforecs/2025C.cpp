#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    map<ll, ll> freq;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }
    sort(a.begin(), a.end());
    vector<ll> unique;
    for (ll i = 0; i < n; i++)
    {
        if (freq[a[i]] && (i == 0 || a[i] != a[i - 1]))
        {
            unique.push_back(a[i]);
        }
    }
    // cout << "unique size & map size : " << unique.size() << " " << freq.size() << endl;
    ll l = 0, r = 0;
    ll curr = freq[unique[0]];
    ll ans = curr;
    while (r < unique.size())
    {
        if (r - l + 1 == k)
        {
            curr -= freq[unique[l]];
            l++;
        }
        else
        {
            if (r + 1 < unique.size() && unique[r + 1] > unique[r] + 1)
            {
                r++;
                l = r;
                curr = freq[unique[r]];
                ans = max(ans, curr);
            }
            else if (r + 1 < unique.size() && unique[r + 1] == unique[r] + 1)
            {
                curr += freq[unique[r + 1]];
                r++;
                ans = max(ans, curr);
            }
            else
            {
                r++;
            }
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