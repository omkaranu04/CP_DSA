#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll l, r;
    cin >> l >> r;
    ll curr = l;
    ll diff = 1;
    vector<ll> a;
    while (curr <= r)
    {
        a.push_back(curr);
        curr += diff;
        diff++;
    }
    if (a.back() > r)
    {
        a.pop_back();
    }
    cout << a.size() << endl;
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