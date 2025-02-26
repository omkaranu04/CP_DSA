#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, d, k;
    cin >> n >> d >> k;
    vector<ll> a(n + 1, 0);
    for (int i = 0; i < k; i++)
    {
        ll l, r;
        cin >> l >> r;
        a[l]++;
        if (r + 1 <= n)
            a[r + 1]--;
    }
    for (int i = 2; i <= n; i++)
    {
        a[i] += a[i - 1];
    }
    vector<ll> ps(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        ps[i] += (ps[i - 1] + a[i]);
    }
    ll m = 0, l = 1e18, robert = 0, mom = 0;
    for (int i = 1; i <= n - d + 1; i++)
    {
        ll jobs = ps[i + d - 1] - ps[i - 1];
        if (jobs > m)
        {
            m = jobs;
            robert = i;
        }
        if (jobs < l)
        {
            l = jobs;
            mom = i;
        }
    }
    cout << "ans " << robert << " " << mom << endl;
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