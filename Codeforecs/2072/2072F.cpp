#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool isOdd(ll n, ll r)
{
    while (n > 0 && r > 0)
    {
        if ((n & 1) < (r & 1))
            return false;
        n >>= 1;
        r >>= 1;
    }
    return true;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> ans;
    for (int i = 0; i < n; i++)
    {
        ll temp = 0;
        for (ll bit = 0; bit < 32; bit++)
        {
            if ((k >> bit) & 1)
            {
                if (isOdd(n - 1, i))
                    temp |= (1 << bit);
            }
        }
        ans.push_back(temp);
    }
    for (auto i : ans)
        cout << i << " ";
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