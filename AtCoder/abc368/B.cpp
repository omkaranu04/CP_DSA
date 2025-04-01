#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    sort(a.rbegin(), a.rend());
    ll ans = 0;
    while (a[0] != 0 && a[1] != 0)
    {
        a[0]--;
        a[1]--;
        sort(a.rbegin(), a.rend());
        ans++;
    }
    cout << ans << endl;
    return 0;
}