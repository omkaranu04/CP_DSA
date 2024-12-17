#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    set<ll> used, avail;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        avail.insert(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (used.find(a[i]) == used.end())
        {
            b[i] = a[i];
            used.insert(a[i]);
            avail.erase(a[i]);
        }
        else
        {
            b[i] = *avail.begin();
            avail.erase(avail.begin());
            used.insert(b[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
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