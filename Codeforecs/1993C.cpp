#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll mini = *min_element(a.begin(), a.end());
    vector<ll> b(n);
    for (int i = 0; i < n; i++)
    {
        b[i] = (a[i] - mini) % (2 * k);
    }
    sort(b.begin(), b.end());
    ll l = 0, r = k;
    for (auto i : b)
    {
        if (i < k)
            l = max(i, l);
        else
            r = min(r, i - k);
    }
    if (r <= l)
    {
        cout << -1 << endl;
        return;
    }

    int maxi = *max_element(a.begin(), a.end());
    int reduced_maxi = (maxi - mini) % (2 * k);
    if (reduced_maxi < k)
    {
        maxi -= reduced_maxi;
        maxi += l;
    }
    else
    {
        maxi += (2 * k) - reduced_maxi;
        maxi += l;
    }
    cout << maxi << endl;
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