#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll num = n;
        vector<ll> ans;
        for (int i = 63; i >= 0; i--)
        {
            long long x = 1LL << i;
            if ((x & n) == x && x != n)
                ans.push_back(n - x);
        }
        ans.push_back(n);
        cout << ans.size() << endl;
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}