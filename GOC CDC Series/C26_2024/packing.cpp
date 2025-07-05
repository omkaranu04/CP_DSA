#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    vector<string> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll up = 1e9, down = -1, left = 1e9, right = -1;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (a[i][j] == '0')
                continue;
            up = min(up, i);
            down = max(down, i);
            left = min(left, j);
            right = max(right, j);
        }
    }
    cout << up + 1 << " " << left + 1 << " " << down + 1 << " " << right + 1 << endl;
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