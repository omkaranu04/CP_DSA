#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int mod = 1000000;
ll nearest_square(ll n)
{
    ll i = 1;
    while (true)
    {
        if (i * i > n)
        {
            return i - 1;
        }
        i++;
    }
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> ans(n + 1);
    vector<bool> visited(n + 1, false);
    map<ll, ll> mp;
    ll curr_color = 1;
    ll ns = nearest_square(n - 1);
    if (n == 3)
    {
        cout << "-1" << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            ll j = i;
            ll x = ns * ns;
            if (x == 1)
            {
                while (j <= n && visited[j] == false)
                {
                    ans[j] = curr_color;
                    visited[j] = true;
                    j++;
                }
            }
            while (j + x <= n && visited[j + x] == false && visited[j] == false)
            {
                ans[j] = curr_color;
                ans[j + x] = curr_color;
                visited[j] = true;
                visited[j + x] = true;
                j++;
                curr_color = (curr_color + 1) % mod;
                curr_color = (curr_color == 0) ? 1 : curr_color;
            }
            ns--;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        mp[ans[i]]++;
    }
    for (auto x : mp)
    {
        // cout << x.first << " " << x.second << endl;
        if (x.second < 2)
        {
            cout << "-1" << endl;
            return;
        }
    }
    for (ll i = 1; i < n + 1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return;
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