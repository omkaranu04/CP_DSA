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
    ll N, S, L;
    cin >> N >> S >> L;
    vector<ll> a(N - 1);
    for (ll i = 0; i < N - 1; i++)
        cin >> a[i];
    S--;
    vector<ll> d(N, 0);
    for (ll i = S + 1; i < N; i++)
        d[i] = d[i - 1] + a[i - 1];
    for (ll i = S - 1; i >= 0; i--)
        d[i] = d[i + 1] + a[i];
    ll ans = 1;
    for (ll left = 0; left <= S; left++)
    {
        for (ll right = S; right < N; right++)
        {
            ll dl = d[left], dr = d[right];
            ll c = min(2 * dl + dr, 2 * dr + dl);
            if (c <= L)
                ans = max(ans, right - left + 1);
        }
    }
    cout << ans;
    return 0;
}