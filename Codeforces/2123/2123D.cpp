#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll cnt1 = 0;
    for (auto c : s)
        if (c == '1')
            cnt1++;
    if (cnt1 <= k)
    {
        cout << "Alice\n";
        return;
    }
    if (n >= 2 * k)
    {
        cout << "Bob\n";
        return;
    }
    cout << "Alice\n";
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