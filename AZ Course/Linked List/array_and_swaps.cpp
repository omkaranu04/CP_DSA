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
    map<ll, ll> freq;
    ll maxi = 0;
    for (ll i = 0; i < n; i++)
    {
        freq[a[i]]++;
        maxi = max(maxi, freq[a[i]]);
    }
    if (maxi > (n + 1) / 2)
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;
}