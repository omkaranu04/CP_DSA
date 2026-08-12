#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        long double l = ceil(sqrtl(sum));
        long double r = floor(sqrtl(sum));
        if (l == r)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}