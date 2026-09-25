#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
const ll MAXN = 102, MAXX = 1010;
ll N;
ll x[MAXN];
bool p[MAXN * MAXX];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(p, false, sizeof(p));
    cin >> N;
    ll s = 0;
    for (ll i = 1; i <= N; i++)
    {
        cin >> x[i];
        s += x[i];
    }
    p[0] = true;
    for (ll i = 1; i <= N; i++)
        for (ll t = s; t >= x[i]; t--)
            if (p[t - x[i]])
                p[t] = true;
    set<ll> ans;
    for (ll i = 1; i <= s; i++)
        if (p[i])
            ans.insert(i);
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << " ";
    return 0;
}