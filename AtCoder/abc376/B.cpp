#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, q;
    cin >> n >> q;
    vector<char> h(q);
    vector<ll> t(q);
    for (ll i = 0; i < q; i++)
    {
        cin >> h[i] >> t[i];
        t[i]--;
    }
    ll currL = 0, currR = 1;
    ll ans = 0;
    for (int i = 0; i < q; i++)
    {
        if (h[i] == 'L')
        {
        }
        if (h[i] == 'R')
        {
        }
    }
    return 0;
}