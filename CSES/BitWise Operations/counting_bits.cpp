#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll noOf1sFrom0(ll x, ll i)
{
    ll tot = x + 1;
    ll cyc = (1LL << (i + 1));
    ll tot_cyc = tot / cyc;
    ll rem = tot % cyc;
    ll rem1s = max(0LL, rem - (1LL << i));
    ll ans = tot_cyc * (1LL << i) + rem1s;
    return ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 0; i < 64; i++)
    {
        ll x = (1LL << i);
        if (x > n)
            break;
        ans += noOf1sFrom0(n, i);
    }
    cout << ans << endl;
    return 0;
}