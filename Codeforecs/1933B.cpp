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
        vector<ll> ps(n + 1);
        ps[0] = 0;
        ll sum = 0;
        bool some = false;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            if (a[i] % 3 == 1)
                some = true;
        }
        if (sum % 3 == 0)
            cout << 0 << endl;
        else if (sum % 3 == 2)
            cout << 1 << endl;
        else
        {
            if (some)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
    }
    return 0;
}