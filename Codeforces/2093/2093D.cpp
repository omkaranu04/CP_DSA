#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
pair<ll, ll> fp(ll x, ll y, ll size, ll start)
{
    // base case
    if (size == 2)
    {
        ll dx[4] = {0, 1, 1, 0};
        ll dy[4] = {0, 1, 0, 1};
        ll val[4];
        for (int i = 0; i < 4; i++)
        {
            val[i] = start + i;
            if (x == dx[i] && y == dy[i])
                return {val[i], -1};
        }
    }

    ll half = size / 2;
    ll area = (size * size) / 4;

    if (x < half && y < half)
        return fp(x, y, half, start);
    else if (x >= half && y >= half)
        return fp(x - half, y - half, half, start + area);
    else if (x >= half && y < half)
        return fp(x - half, y, half, start + 2 * area);
    else
        return fp(x, y - half, size, start + 3 * area);
}
pair<ll, ll> fc(ll num, ll size, ll start, ll x, ll y)
{
    // base case
    if (size == 2)
    {
        ll dx[4] = {0, 1, 1, 0};
        ll dy[4] = {0, 1, 0, 1};
        for (int i = 0; i < 4; i++)
        {
            if (start + i == num)
                return {x + dx[i] + 1, y + dy[i] + 1};
        }
    }

    ll half = size / 2;
    ll area = (size * size) / 4;

    if (num < start + area)
        return fc(num, half, start, x, y);
    else if (num < start + 2 * area)
        return fc(num, half, start + area, x + half, y + half);
    else if (num < start + 3 * area)
        return fc(num, half, start + 2 * area, x + half, y);
    else
        return fc(num, half, start + 3 * area, x, y + half);
}
void solve()
{
    ll n;
    cin >> n;
    ll q;
    cin >> q;
    ll size = 1LL << n;
    while (q--)
    {
        string t;
        cin >> t;
        if (t == "->")
        {
            ll x, y;
            cin >> x >> y;
            pair<ll, ll> ans = fp(x - 1, y - 1, size, 1);
            cout << ans.first << endl;
        }
        if (t == "<-")
        {
            ll num;
            cin >> num;
            pair<ll, ll> ans = fc(num, size, 1, 0, 0);
            cout << ans.first << " " << ans.second << endl;
        }
    }
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