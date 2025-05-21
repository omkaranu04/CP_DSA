#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll maxi = 0, sum = 0;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    maxi = a[n - 1];
    sum = accumulate(a.begin(), a.end() - 1, 0LL);
    ll ans;
    if (maxi <= sum)
        ans = sum + maxi;
    else
        ans = 2 * maxi;
    cout << ans << endl;
    return 0;
}