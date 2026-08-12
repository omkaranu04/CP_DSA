#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        ll count = 0;
        ll m = min(n, x);
        for (ll a = 1; a <= m; ++a)
        {
            for (ll b = 1; b <= m - a && a * b < n; ++b)
            {
                if (a + b >= x)
                    break;

                ll c = min(x - a - b, (n - a * b) / (a + b));

                if (c >= 1)
                {
                    count += c;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}