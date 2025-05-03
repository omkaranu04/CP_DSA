#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, k;
    cin >> n >> k;
    ll maxk = 0;
    ll nn = n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        maxk += abs(i - nn);
        nn--;
        a[i] = i;
    }
    if (k % 2 == 1)
    {
        cout << "No" << endl;
        return;
    }
    else if (k > maxk)
    {
        cout << "No" << endl;
        return;
    }
    else if (k == 0)
    {
        cout << "Yes" << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    else if (k == maxk)
    {
        cout << "Yes" << endl;
        for (int i = n; i >= 1; i--)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    else
    {
        ll l = 1, r = n;
        while (l < r)
        {
            ll x = 2 * abs(a[l] - a[r]);
            if (x > k)
                r--;
            else
            {
                k -= x;
                swap(a[l], a[r]);
                l++;
                r--;
            }
        }
        cout << "Yes" << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
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