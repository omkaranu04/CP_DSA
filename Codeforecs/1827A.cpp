#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n), acount(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i++)
        {
            acount[i] = n - (upper_bound(a.begin(), a.end(), b[i]) - a.begin());
        }
        reverse(acount.begin(), acount.end());
        ll answer = 1;
        for (int i = 0; i < n; i++)
        {
            acount[i] = acount[i] - i;
            answer = ((answer % mod) * (acount[i] % mod)) % mod;
        }
        cout << answer << endl;
    }
    return 0;
}