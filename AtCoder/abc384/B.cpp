#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, r;
    cin >> n >> r;
    vector<ll> d(n), a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> d[i] >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        if (d[i] == 1)
        {
            if (r >= 1600 && r <= 2799)
                r += a[i];
        }
        if (d[i] == 2)
        {
            if (r >= 1200 && r <= 2399)
                r += a[i];
        }
    }
    cout << r << endl;
    return 0;
}