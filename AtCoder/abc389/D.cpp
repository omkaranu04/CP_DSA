#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool dis(ll a, ll b, ll r)
{
    ll t1 = (2 * a + 1) * (2 * a + 1);
    ll t2 = (2 * b + 1) * (2 * b + 1);
    t1 += t2;
    return t1 <= 4 * r * r;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll r;
    cin >> r;
    ll tmp = 0, up = r - 1, ans = 0;
    if (dis(0, 0, r))
        ans++;
    for (ll x = 1; x <= r; x++)
    {
        while (up >= 0 && !dis(x, up, r))
            --up;
        tmp += up + 1;
    }
    ans += 4 * tmp;
    cout << ans << endl;
    return 0;
}