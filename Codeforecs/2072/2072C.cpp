#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n, x);
    ll v = 0;
    bool flag = true;
    for (ll m = 0; m < n - 1; m++)
    {
        ll temp = v | m;
        if ((temp & x) == temp)
        {
            v = temp;
            a[m] = m;
        }
        else
        {
            flag = false;
            break;
        }
    }
    if (flag == true && (v | (n - 1)) == x)
        a[n - 1] = n - 1;
    for (auto i : a)
        cout << i << " ";
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