#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    string s;
    cin >> n;
    cin >> s;
    vector<ll> ones;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            ones.push_back(i + 1);
        }
    }
    ll m = ones.size();
    ll ans = 0;
    for (ll i = 0; i < m; i++)
        ones[i] -= i;
    ll median = ones[m / 2];
    for (ll i = 0; i < m; i++)
    {
        ans += abs(ones[i] - median);
    }
    cout << ans << endl;
    return 0;
}