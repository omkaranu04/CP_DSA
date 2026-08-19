#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll countDivisors(ll n)
{
    int count = 0;
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
            count += (i * i == n) ? 1 : 2;
    }
    return count;
}
void solve()
{
    ll n;
    cin >> n;
    if (n % 2 == 0)
        cout << countDivisors(n / 2) << endl;
    else
        cout << 0 << endl;
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