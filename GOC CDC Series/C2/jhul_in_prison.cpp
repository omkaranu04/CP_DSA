#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll x, y;
    cin >> x >> y;
    vector<ll> a(x), b(y);
    for (ll i = 0; i < x; i++)
        cin >> a[i];
    for (ll i = 0; i < y; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll maxa = 1, curra = 1;
    for (ll i = 1; i < x; i++)
    {
        if (a[i] == a[i - 1] + 1)
            curra++;
        else
            curra = 1;
        maxa = max(maxa, curra);
    }
    ll maxb = 1, currb = 1;
    for (ll i = 1; i < y; i++)
    {
        if (b[i] == b[i - 1] + 1)
            currb++;
        else
            currb = 1;
        maxb = max(maxb, currb);
    }
    cout << (maxa + 1LL) * 1LL * (maxb + 1LL) << endl;
    return 0;
}