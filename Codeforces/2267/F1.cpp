#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll spr(vector<ll> &a)
{
    ll mx = *max_element(a.begin(), a.end());
    ll mn = *min_element(a.begin(), a.end());
    return mx - mn;
}
void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;

    vector<ll> d, curr = a;
    d.push_back(spr(curr));

    vector<ll> tmp;
    tmp.reserve((n * n) / 2);
    for (ll s = 1; s <= 100; s++)
    {
        bool flag = true;
        for (auto x : curr)
            if (x)
                flag = false;
        if (flag)
            break;

        tmp.clear();
        for (ll i = 0; i < n; i++)
        {
            for (ll j = i + 1; j < n; j++)
            {
                tmp.push_back(curr[i] ^ curr[j]);
            }
        }
        nth_element(tmp.begin(), tmp.begin() + n - 1, tmp.end());
        curr.assign(tmp.begin(), tmp.begin() + n);
        d.push_back(spr(curr));
    }

    while (q--)
    {
        ll x;
        cin >> x;
        if (x < d.size())
            cout << d[x] << endl;
        else
            cout << d.back() << endl;
    }
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