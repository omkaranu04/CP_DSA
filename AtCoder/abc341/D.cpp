#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, k;
    cin >> n >> m >> k;
    ll lcm_nm = n * m / __gcd(n, m);
    ll l = 1, r = 1e18, res = -1;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;

        ll cn = mid / n;
        ll cm = mid / m;
        ll clcm = mid / lcm_nm;

        ll ones = cn + cm - 2 * clcm;
        if (ones >= k)
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << res << endl;
    return 0;
}