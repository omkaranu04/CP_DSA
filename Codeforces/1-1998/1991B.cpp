#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> b(n - 1), a(n);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> b[i];
    }
    a[0] = b[0];
    for (int i = 1; i < n - 1; i++)
    {
        a[i] = (a[i - 1] & b[i - 1]) | b[i];
    }
    a[n - 1] = a[n - 2] & b[n - 2];
    bool isGood = true;
    for (int i = 1; i <= n - 1; i++)
    {
        if ((a[i] & a[i - 1]) != b[i - 1])
        {
            isGood = false;
        }
    }
    if (isGood)
    {
        for (auto i : a)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
    return;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}