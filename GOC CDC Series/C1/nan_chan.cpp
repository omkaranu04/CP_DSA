#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll x, a, b;
        cin >> x >> a >> b;
        ll tmp = (a * b) / __gcd(a, b);
        cout << x + tmp << endl;
    }
}