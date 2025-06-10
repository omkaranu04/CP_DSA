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
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll curr = 0, ans = 0;
    for (ll i = 0; i < n; i++)
    {
        curr += a[i];
        ans = min(ans, curr);
    }
    cout << curr - ans;
    return 0;
}