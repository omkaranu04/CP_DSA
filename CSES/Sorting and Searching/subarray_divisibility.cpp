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
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // target reduction, search for start, at an given end
    ll ans = 0;
    ll curr = 0;
    // use map only, no unordered map
    map<ll, ll> mp;
    mp[curr]++;
    for (int i = 0; i < n; i++)
    {
        curr += a[i];
        curr = (curr % n + n) % n;
        if (mp.find(curr) != mp.end())
        {
            ans += mp[curr];
        }
        mp[curr]++;
    }
    cout << ans << endl;
    return 0;
}