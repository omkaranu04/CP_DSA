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
        ll n;
        cin >> n;
        ll max_sum = -1;
        ll x = -1;
        for (ll i = 2; i <= n; i++)
        {
            ll k = n / i;
            ll sum = (i * k * (k + 1)) / 2;
            if (sum >= max_sum && k * i <= n)
            {
                x = i;
                max_sum = sum;
            }
        }
        cout << x << endl;
    }
    return 0;
}