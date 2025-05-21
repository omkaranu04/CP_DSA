#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

ll factors(ll n)
{
    ll ans = 1;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ll tmp = 0;
            while (n % i == 0)
                n /= i, tmp++;
            ans *= (2 * tmp + 1);
        }
    }
    if (n > 1)
        ans *= 3;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll N;
    cin >> N;
    ll ans = factors(N);
    cout << ans << endl;
}