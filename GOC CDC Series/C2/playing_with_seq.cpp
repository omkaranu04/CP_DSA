#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    bitset<4000010> bs;
    bs.set(0);
    for (auto x : a)
        bs |= (bs << x);
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    ll med = sum / 2;
    if (sum % 2 == 1)
        med++;
    for (ll i = med; i <= sum; i++)
    {
        if (bs[i])
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
