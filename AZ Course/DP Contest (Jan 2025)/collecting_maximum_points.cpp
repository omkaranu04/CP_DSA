#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n;
vector<ll> a;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    a.resize(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll prev2 = 0, prev1 = 0;
    for (ll i = 0; i < n; i++)
    {
        ll curr = max(prev1, prev2 + a[i]);
        prev2 = prev1;
        prev1 = curr;
    }
    cout << prev1;
    return 0;
}