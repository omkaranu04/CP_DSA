#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, d;
    cin >> n >> d;
    vector<ll> freq(1000010, 0);
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        freq[x]++;
    }
    ll ans = 0;
    if (d == 0)
    {
        for (auto x : freq)
        {
            if (x > 1)
                ans += (x - 1);
        }
    }
    else
    {
        for (int i = 0; i + d < freq.size(); i++)
        {
            ll temp = min(freq[i], freq[i + d]);
            ans += temp;
            freq[i] -= temp;
            freq[i + d] -= temp;
        }
    }
    cout << ans << endl;
    return 0;
}