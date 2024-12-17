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
        ll n, m, k;
        cin >> n >> m >> k;
        vector<ll> ans;
        for (int i = n; i >= m + 1; i--)
        {
            ans.push_back(i);
        }
        for (int i = 1; i <= m; i++)
        {
            ans.push_back(i);
        }
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}