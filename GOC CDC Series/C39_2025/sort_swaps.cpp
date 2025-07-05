#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
inline ll pc(ll x) { return (ll)__builtin_popcount(x); }
ll mergesort(vector<ll> &a, vector<ll> &tmp, ll l, ll r)
{
    if (r - l <= 1)
        return 0;
    ll mid = (l + r) / 2;
    ll ans = mergesort(a, tmp, l, mid) + mergesort(a, tmp, mid, r);
    ll i = l, j = mid, k = l;
    while (i < mid || j < r)
    {
        if (j == r || (i < mid && a[i] <= a[j]))
            tmp[k++] = a[i++];
        else
        {
            tmp[k++] = a[j++];
            ans += (mid - i);
        }
    }
    for (ll z = l; z < r; z++)
        a[z] = tmp[z];
    return ans;
}
void clove()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1)
    {
        cout << "0\n";
        return;
    }
    vector<vector<ll>> b;
    b.push_back({});
    b.back().push_back(a[0]);
    for (ll i = 1; i < n; i++)
    {
        if (pc(a[i]) == pc(a[i - 1]))
            b.back().push_back(a[i]);
        else
            b.push_back({a[i]});
    }
    bool poss = true;
    ll pmax = *max_element(b[0].begin(), b[0].end());
    for (ll i = 1; i < b.size(); i++)
    {
        ll cm = *min_element(b[i].begin(), b[i].end());
        if (pmax > cm)
        {
            poss = false;
            break;
        }
        pmax = max(pmax, *max_element(b[i].begin(), b[i].end()));
    }
    if (!poss)
    {
        cout << "-1\n";
        return;
    }
    ll ans = 0;
    for (auto &x : b)
    {
        vector<ll> tmp(x.size()), xx = x;
        ans += mergesort(xx, tmp, 0, x.size());
    }
    cout << ans << endl;
    return;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
        clove();
    return 0;
}