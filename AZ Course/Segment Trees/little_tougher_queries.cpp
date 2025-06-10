#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
const ll N = 100100;
vector<ll> st[4 * N];
vector<ll> a(N);
void build(ll id, ll l, ll r)
{
    for (ll i = l; i <= r; i++)
        st[id].push_back(a[i]);
    sort(st[id].begin(), st[id].end());
    if (l == r)
        return;
    ll mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
}
ll bs(vector<ll> &a, ll x) // how many elements <= x
{
    ll lo = 0, hi = a.size() - 1, ans = -1;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (a[mid] <= x)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return ans + 1;
}
ll query(ll id, ll l, ll r, ll ql, ll qr, ll x)
{
    if (ql > r || l > qr)
        return 0;
    if (l >= ql && r <= qr)
        return bs(st[id], x);
    ll mid = (l + r) / 2;
    return query(2 * id, l, mid, ql, qr, x) + query(2 * id + 1, mid + 1, r, ql, qr, x);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, q;
    cin >> n >> q;
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    build(1, 0, n - 1);

    while (q--)
    {
        ll l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        ll lo = 0, hi = 1e9, ans = -1;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            if (query(1, 0, n - 1, l, r, mid) >= k)
            {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        cout << ans << endl;
    }
    return 0;
}