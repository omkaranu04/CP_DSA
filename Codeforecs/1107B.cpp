#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    while (n--)
    {
        ll k, x;
        cin >> k >> x;
        ll ans = x;
        k--;
        while (k--)
        {
            ans += 9;
        }
        cout << ans << endl;
    }
    return 0;
}