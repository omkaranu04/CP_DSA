#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ll x;
    cin >> x;
    ll ans = 0;
    ll mul = 1;
    while (x / 10 > 0)
    {
        ll temp = x % 10;
        if (temp >= 5)
        {
            ans += (9 - temp) * mul;
        }
        else
        {
            ans += temp * mul;
        }
        mul *= 10;
        x /= 10;
    }
    if (x == 9)
        ans += x * mul;
    else if (x >= 5 && x != 9)
    {
        ans += (9 - x) * mul;
    }
    else
    {
        ans += x * mul;
    }
    cout << ans << endl;
    return 0;
}