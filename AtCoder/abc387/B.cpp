#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll x;
    cin >> x;
    ll ans = 0;
    for (ll i = 0; i < 9; i++)
    {
        for (ll j = 0; j < 9; j++)
        {
            ll temp = (i + 1) * (j + 1);
            if (temp != x)
                ans += temp;
        }
    }
    cout << ans << endl;
    return 0;
}