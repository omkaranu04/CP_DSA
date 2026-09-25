#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (auto &x : a)
            cin >> x;
        vector<ll> cnt(110, 0);
        for (auto &x : a)
            cnt[x]++;
        vector<ll> ans, vals;

        for (ll i = 100; i >= 1; i--)
            if (cnt[i])
                vals.push_back(i);
        ll mode = 0;
        for (ll i = 1; i <= 100; i++)
            mode = max(mode, cnt[i]);

        for (ll l = 1; l <= mode; l++)
        {
            for (auto x : vals)
            {
                if (cnt[x] >= l)
                    ans.push_back(x);
            }
        }

        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}