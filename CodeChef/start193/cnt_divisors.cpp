#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    ll odd = 0, even = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i % 2 == 0)
                even++;
            else
                odd++;
        }
    }
    cout << odd << " " << even << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}