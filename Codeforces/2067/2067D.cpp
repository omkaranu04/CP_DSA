#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;

    if (n == 1)
    {
        ll dummy;
        cin >> dummy;
        cout << "! A\n";
        cout.flush();
        return;
    }

    vector<ll> a(n + 1), freq(n + 1, 0);
    ll idx1 = -1, idxn = -1;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }
    bool flag = true;
    int i;
    for (i = 1; i <= n; i++)
    {
        if (freq[i] == 0)
        {
            flag = false;
            break;
        }
    }
    if (flag == false)
    {
        ll x;
        if (i == 1)
            x = i + 1;
        else
            x = i - 1;
        cout << "? " << i << " " << x << "\n";
        cout.flush();
        ll res;
        cin >> res;

        if (res == -1)
            exit(0);

        if (res == 0)
        {
            cout << "! A\n";
            cout.flush();
            return;
        }
        else
        {
            cout << "! B\n";
            cout.flush();
            return;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
            idx1 = i;
        if (a[i] == n)
            idxn = i;
    }
    ll res1, res2;
    cout << "? " << idx1 << " " << idxn << "\n";
    cout.flush();
    cin >> res1;
    if (res1 == -1)
        exit(0);
    cout << "? " << idxn << " " << idx1 << "\n";
    cout.flush();
    cin >> res2;
    if (res2 == -1)
        exit(0);
    if (res1 == res2 && res1 >= n - 1)
    {
        cout << "! B\n";
        cout.flush();
    }
    else
    {
        cout << "! A\n";
        cout.flush();
    }
    cout.flush();
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