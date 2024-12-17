#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    ll ans = 1, prev = a[0].second;
    for (ll i = 1; i < n; i++)
    {
        if (a[i].second < prev)
            ans++;
        prev = a[i].second;
    }
    cout << ans << endl;
    return 0;
}