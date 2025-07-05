#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> cnt(4, 0);
    for (ll i = 0; i < n; i++)
        cnt[i % 4]++;
    if (cnt[0] == cnt[3] && cnt[1] == cnt[2])
        cout << "Bob\n";
    else
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