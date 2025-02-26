#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> queens;
vector<ll> dx = {1, 1, 2, 2, -1, -1, -2, -2};
vector<ll> dy = {2, -2, 1, -1, 2, -2, 1, -1};
bool check(ll r, ll c, ll n)
{
    for (ll i = 0; i < r; i++)
    {
        ll j = queens[i];
        if (j == c || abs(i - r) == abs(j - c))
        {
            return false;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (r + dx[i] >= 0 && r + dx[i] < n && c + dy[i] >= 0 && c + dy[i] < n)
        {
            if (queens[r + dx[i]] == c + dy[i])
            {
                return false;
            }
        }
    }
    return true;
}
int place_queens(int level, ll n)
{
    if (level == n)
        return 1;
    ll tmp = 0;
    for (ll i = 0; i < n; i++)
    {
        if (check(level, i, n))
        {
            queens[level] = i;
            tmp += place_queens(level + 1, n);
            queens[level] = -1;
        }
    }
    return tmp;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    queens.resize(n);
    for (ll i = 0; i < n; i++)
    {
        queens[i] = -1;
    }
    ll ans = place_queens(0, n);
    cout << ans << "\n";
}