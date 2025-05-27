#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int n, k;
ll a[110], dp[100100];
ll rec(ll x)
{
    if (x == 0)
        return 0;
    if (dp[x] != -1)
        return dp[x];

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (x - a[i] >= 0 && rec(x - a[i]) == 0)
        {
            ans = 1;
            break;
        }
    }

    return dp[x] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // cout << (rec(k) ? "First" : "Second") << endl;

    // iter solution
    vector<bool> dp2(k + 1, false);
    for (int i = 0; i <= k; i++)
    {
        for (int x : a)
        {
            if (i - x >= 0 && dp2[i - x] == false)
            {
                dp2[i] = true;
            }
        }
    }
    cout << (dp2[k] ? "First" : "Second") << endl;
    return 0;
}