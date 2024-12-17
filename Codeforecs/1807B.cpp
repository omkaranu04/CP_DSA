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
        ll odd = 0, even = 0;
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 0)
                even += a[i];
            else
                odd += a[i];
        }
        if (even > odd)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}