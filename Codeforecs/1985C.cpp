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
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll ps = 0;
        ll count = 0;
        ll maxi = -1;
        for (int i = 0; i < n; i++)
        {
            ps += a[i];
            maxi = max(maxi, a[i]);
            if (ps == 2 * maxi)
                count++;
        }
        cout << count << endl;
    }
    return 0;
}