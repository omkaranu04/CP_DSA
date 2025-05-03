#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll get_add(ll x)
{
    ll mini = 1000, maxi = -1;
    while (x > 0)
    {
        ll y = x % 10;
        mini = min(mini, y);
        maxi = max(maxi, y);
        x /= 10;
    }
    return mini * maxi;
}
int main(int argc, char const *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a1, k;
        cin >> a1 >> k;
        k--;
        while (k--)
        {
            ll ans = get_add(a1);
            if (ans == 0)
                break;
            a1 += ans;
        }
        cout << a1 << endl;
    }
    return 0;
}