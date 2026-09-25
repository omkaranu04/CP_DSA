#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll c;
        cin >> c;
        ll a = c;
        ll b = c;
        for (ll i = 1; i <= 24; i++)
            b = b * 2;
        cout << a << " " << b << endl;
    }
    return 0;
}