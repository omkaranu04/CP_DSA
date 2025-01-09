#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> c(n);
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        m[c[i]]++;
    }
    ll ans = 0, cnt = 0;
    for (auto i : m)
    {
        if (i.second > 1)
            ans++;
        if (i.second == 1)
            cnt++;
    }
    ans += 2 * (ceil(cnt / 2.0));
    cout << ans << endl;
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