#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = n - k + 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    for (ll i = 1; i <= n - k; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}