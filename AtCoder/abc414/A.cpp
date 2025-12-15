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
    ll N, L, R;
    cin >> N >> L >> R;
    ll ans = 0;
    for (ll i = 0; i < N; i++)
    {
        ll X, Y;
        cin >> X >> Y;
        if (X <= L && Y >= R)
            ans++;
    }
    cout << ans << endl;
    return 0;
}