#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // --- //
    vector<ll> track;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != a[i + 1])
            track.push_back(i);
    }
    sort(track.begin(), track.end());
    // --- //
    ll q;
    cin >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        ll low = 0, high = track.size() - 1;
        ll p = -1;
        while (low <= high)
        {
            ll mid = (low + high) / 2;
            if (track[mid] >= l)
            {
                p = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        if (p != -1 && track[p] < r)
            cout << track[p] + 1 << " " << track[p] + 2 << endl;
        else
            cout << "-1 -1" << endl;
    }
    cout << endl;
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