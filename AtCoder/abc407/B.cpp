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
    vector<pair<ll, ll>> poss;
    for (ll i = 1; i <= 6; i++)
    {
        for (ll j = 1; j <= 6; j++)
        {
            poss.push_back({i, j});
        }
    }
    ll X, Y;
    cin >> X >> Y;
    ll cnt = 0;
    for (auto &[a, b] : poss)
    {
        if ((a + b >= X) || (abs(a - b) >= Y))
            cnt++;
    }
    long double ans = (long double)cnt / 36.0;
    cout << setprecision(15) << ans << endl;
    return 0;
}