#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll cntmerge(vector<ll> &ps, ll l, ll mid, ll r)
{
    ll n1 = mid - l + 1, n2 = r - mid;
    vector<ll> left(n1), right(n2);
    for (ll i = 0; i < n1; i++)
        left[i] = ps[l + i];
    for (ll i = 0; i < n2; i++)
        right[i] = ps[mid + 1 + i];

    ll ans = 0;
    ll i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            ps[k++] = left[i++];
        else
        {
            ps[k++] = right[j++];
            ans += (n1 - i);
        }
    }
    while (i < n1)
        ps[k++] = left[i++];
    while (j < n2)
        ps[k++] = right[j++];
    return ans;
}
ll countinv(vector<ll> &ps, ll l, ll r)
{
    ll ans = 0;
    if (l < r)
    {
        ll mid = (l + r) / 2;
        ans += countinv(ps, l, mid);
        ans += countinv(ps, mid + 1, r);
        ans += cntmerge(ps, l, mid, r);
    }
    return ans;
}
void solve()
{
    ll n;
    cin >> n;
    string S;
    cin >> S;
    vector<ll> ps(n + 1, 0);
    for (ll i = 0; i < n; i++)
        ps[i + 1] = ((S[i] == '1') ? 1 : -1);
    for (ll i = 1; i <= n; i++)
        ps[i] += ps[i - 1];
    reverse(ps.begin(), ps.end());
    ll ans = countinv(ps, 0, n);
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