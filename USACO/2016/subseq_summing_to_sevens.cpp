#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    ll N;
    cin >> N;
    vector<ll> a(N);
    for (auto &x : a)
        cin >> x;
    ll sum = 0, ans = LLONG_MIN;
    vector<ll> mp(7, -1);
    mp[0] = 0;
    for (ll i = 0; i < N; i++)
    {
        sum = (sum + a[i]) % 7;
        if (mp[sum] != -1)
            ans = max(ans, i - mp[sum]);
        else
            mp[sum] = i;
    }
    cout << ans << endl;
    return 0;
}