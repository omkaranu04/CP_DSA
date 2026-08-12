#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll n, k;
    cin >> n >> k;
    string s(n, 'a');
    for (ll i = n - 2; i >= 0; i--)
    {
        if (k <= (n - i - 1))
        {
            s[i] = 'b';
            s[n - k] = 'b';
            cout << s << endl;
            return;
        }
        k -= (n - i - 1);
    }
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