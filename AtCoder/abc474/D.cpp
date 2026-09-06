#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    bool flag = false;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        cout << "No\n";
        return 0;
    }
    vector<ll> w(n, 1);
    for (ll i = 0; i < n; i++)
    {
        if (a[i] > b[i])
            w[i] = 1e18;
    }
    cout << "Yes\n";
    for (auto x : w)
        cout << x << " ";
    return 0;
}