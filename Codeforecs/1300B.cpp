#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(2 * n);
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        cout << abs(a[n] - a[n - 1]) << endl;
    }
    return 0;
}