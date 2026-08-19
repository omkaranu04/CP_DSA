#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    if (n == 1)
        cout << 1;
    else if (n == 2)
        cout << 2;
    else
    {
        if (n % 2 == 1)
            cout << 2;
        else
            cout << 3;
    }
    cout << endl;
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