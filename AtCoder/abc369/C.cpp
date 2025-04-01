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
        cin >> a[i];
    ll l = 0, r = 1, ans = 0;
    ll d = a[r] - a[l];
    while (l < n && r < n)
    {
        ll temp = l;
        // cout << temp << " " << r << " " << d << endl;
        while (r < n && a[r] - a[temp] == d)
        {
            temp++;
            r++;
        }
        r--;
        ll num = r - l;
        ans += (num * (num + 1)) / 2;
        l = r;
        r = l + 1;
        d = a[r] - a[l];
    }
    ans += n;
    cout << ans << endl;
    return 0;
}