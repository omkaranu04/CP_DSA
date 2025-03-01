#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<ll, ll> seen;
    ll l = 0, ans = 1e18;
    for (ll r = 0; r < n; r++)
    {
        seen[a[r]]++;
        while (seen[a[r]] > 1)
        {
            ans = min(ans, r - l + 1);
            seen[a[l]]--;
            l++;
        }
    }
    if (ans == 1e18)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}