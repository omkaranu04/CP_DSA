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
    ll i = 0, j = n - 1;
    while (j >= i && a[j] == 0)
        j--;
    while (j >= i && a[i] == 0)
        i++;
    if (i > j)
    {
        cout << 0 << endl;
        return;
    }

    for (int k = i; k <= j; k++)
    {
        if (a[k] == 0)
        {
            cout << 2 << endl;
            return;
        }
    }
    cout << 1 << endl;
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
    {
        solve();
    }
    return 0;
}