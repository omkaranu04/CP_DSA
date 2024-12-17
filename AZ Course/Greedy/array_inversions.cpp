#include <bits/stdc++.h>
using namespace std;
#define ll long long int
struct node
{
    string s;
    ll cnt0 = 0;
    ll cnt1 = 0;
};
bool cmp(node a, node b)
{
    return a.cnt1 * b.cnt0 < a.cnt0 * b.cnt1;
}
void solve()
{
    ll m;
    cin >> m;
    vector<node> arr(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> arr[i].s;
    }
    for (ll i = 0; i < m; i++)
    {
        for (ll j = 0; j < arr[i].s.size(); j++)
        {
            if (arr[i].s[j] == '0')
            {
                arr[i].cnt0++;
            }
            else
            {
                arr[i].cnt1++;
            }
        }
    }
    sort(arr.begin(), arr.end(), cmp);
    string t;
    for (ll i = 0; i < m; i++)
    {
        t += arr[i].s;
    }
    ll ans = 0;
    ll ones = 0;
    for (ll i = 0; i < t.size(); i++)
    {
        if (t[i] == '1')
        {
            ones++;
        }
        else
        {
            ans += ones;
        }
    }
    cout << ans << "\n";
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