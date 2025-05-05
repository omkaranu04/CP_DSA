#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    if (n % 2 == 0)
        cout << -1 << endl;
    else
    {
        ll mid = n / 2 + 1;
        a[mid] = mid;
        ll counter = 1;
        for (int i = mid + 1; i <= n; i++)
        {
            ll x = i + counter;
            a[i] = (x - 1) % n + 1;
            counter++;
        }
        counter = 1;
        for (int i = mid - 1; i >= 0; i--)
        {
            ll x = i - counter;
            a[i] = (x - 1 + n) % n + 1;
            counter++;
        }
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
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