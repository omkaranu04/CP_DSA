#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
  // followed editorial
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<ll> L(n), R(n), d(m + 1, 1);
    for (ll i = 0; i < n; i++)
    {
        cin >> L[i] >> R[i];
        d[R[i]] = max(d[R[i]], L[i] + 1);
    }
    for (ll i = 1; i <= m; i++)
    {
        d[i] = max(d[i], d[i - 1]);
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans += (i - d[i] + 1);
    }
    cout << ans << endl;
    return 0;
}