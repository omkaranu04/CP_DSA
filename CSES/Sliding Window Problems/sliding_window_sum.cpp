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
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    arr[0] = x;
    for (ll i = 1; i < n; i++)
        arr[i] = (a * arr[i - 1] + b) % c;
    ll ans = 0;
    ll i = 0, j = 0, tmp = 0;
    while (j < k)
    {
        tmp += arr[j];
        j++;
    }
    ans ^= tmp;
    while (i < j && j < n)
    {
        tmp -= arr[i];
        tmp += arr[j];
        i++, j++;
        ans ^= tmp;
    }
    cout << ans << endl;
    return 0;
}