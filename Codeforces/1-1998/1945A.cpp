#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve(ll single, ll poly, ll uni)
{
    ll needPoly = (3 - poly % 3) % 3;
    if (poly > 0 && needPoly > uni)
    {
        cout << "-1\n";
        return;
    }

    uni -= needPoly;
    poly += needPoly;

    ll mn = single + uni / 3 + (uni % 3 + 1) / 2 + poly / 3;
    cout << mn << '\n';
}
int main(int argc, char const *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll single, poly, uni;
        cin >> single >> poly >> uni;
        solve(single, poly, uni);
    }
    return 0;
}