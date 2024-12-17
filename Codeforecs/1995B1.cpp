#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll i = 0, j = 0;
    ll petals = 0, curr_petals = 0;
    while (j < n)
    {
        curr_petals += a[j];

        while (curr_petals > m || (a[j] - a[i] >= 2 && i <= j))
        {
            curr_petals -= a[i];
            i++;
        }

        if (curr_petals <= m)
        {
            petals = max(petals, curr_petals);
        }
        j++;
    }
    cout << petals << endl;
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