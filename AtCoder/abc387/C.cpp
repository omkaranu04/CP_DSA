#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll numberOfDigits(ll x)
{
    ll ans = 0;
    while (x)
    {
        ans++;
        x /= 10;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll l, r;
    cin >> l >> r;
    ll noL = numberOfDigits(l), noR = numberOfDigits(r);
    return 0;
}