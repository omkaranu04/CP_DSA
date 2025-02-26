#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
ll dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
ll dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
bool check(int x, int y, int n)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    set<pair<ll, ll>> s;
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        s.insert({a - 1, b - 1});
        for (int i = 0; i < 8; i++)
        {
            ll x = a - 1 + dx[i];
            ll y = b - 1 + dy[i];
            if (check(x, y, n))
                s.insert({x, y});
        }
    }
    ll ans = n * n - s.size();
    cout << ans << endl;
    return 0;
}