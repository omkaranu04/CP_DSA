#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> ans;
    for (ll i = 0; i < min(x, n); i++)
        ans.push_back(i);
    for (ll i = x + 1; i < n; i++)
        ans.push_back(i);
    if (x < n)
        ans.push_back(x);
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return;
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