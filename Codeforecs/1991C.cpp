#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> ans;
    int i = 0;
    bool flag = false;
    for (i = 0; i < 40; i++)
    {
        ll mini = *min_element(a.begin(), a.end());
        ll maxi = *max_element(a.begin(), a.end());

        if (mini == maxi && mini == 0)
        {
            flag = true;
            break;
        }

        ll x = (mini + maxi) / 2;
        ans.push_back(x);

        for (int i = 0; i < n; i++)
        {
            a[i] = abs(a[i] - x);
        }
    }
    if (flag)
    {
        cout << ans.size() << endl;
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
    return;
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