#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> left, right;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x > 0)
            right.push_back(x);
        else
            left.push_back(x);
    }
    sort(left.rbegin(), left.rend());
    sort(right.begin(), right.end());

    ll l = 0, r = 0, curr = 0, ans = 0;
    while (l < left.size() || r < right.size())
    {
        ll ld = LLONG_MAX, rd = LLONG_MAX;
        if (l < left.size())
            ld = abs(curr - left[l]);
        if (r < right.size())
            rd = abs(curr - right[r]);

        if (ld <= rd)
        {
            ans += abs(curr - left[l]);
            curr = left[l];
            l++;
        }
        else
        {
            ans += abs(curr - right[r]);
            curr = right[r];
            r++;
        }
    }
    cout << ans << endl;
    return 0;
}