#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll qu(ll l, ll r)
{
    cout << "? " << l << " " << r << endl;
    cout.flush();
    ll ret;
    cin >> ret;
    if (ret == -1)
        exit(0);
    return ret;
}
int main(int argc, char const *argv[])
{
    ll n, t;
    cin >> n >> t;
    while (t--)
    {
        ll k;
        cin >> k;
        ll lo = 1, hi = n;
        while (lo < hi)
        {
            ll m = lo + (hi - lo) / 2;
            ll s = qu(1, m);
            ll z = m - s;
            if (z >= k)
                hi = m;
            else
                lo = m + 1;
        }
        cout << "! " << lo << endl;
        cout.flush();
    }
    return 0;
}