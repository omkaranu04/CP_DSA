#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll m;
    cin >> m;
    vector<ll> pox(11);
    pox[0] = 1;
    for (ll i = 1; i <= 10; i++)
        pox[i] = 3 * pox[i - 1];
    vector<ll> ans;
    for (ll i = 10; i >= 0; i--)
    {
        for (; m >= pox[i];)
        {
            m -= pox[i];
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << " ";
    return 0;
}