#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll i1 = 0, j1 = 0, i2 = n - 1, j2 = m - 1;
    ll sum = 0;
    while (i1 <= i2)
    {
        if (abs(a[i1] - b[j2]) >= abs(a[i2] - b[j1]))
        {
            sum += abs(a[i1] - b[j2]);
            i1++;
            j2--;
        }
        else
        {
            sum += abs(a[i2] - b[j1]);
            i2--;
            j1++;
        }
    }
    cout << sum << endl;
    return;
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