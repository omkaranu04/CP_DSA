#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<string> board(8);
vector<ll> queens(8, -1);
bool check(ll r, ll c)
{
    for (ll i = 0; i < r; i++)
    {
        ll j = queens[i];
        if (j == c || abs(i - r) == abs(j - c))
        {
            return false;
        }
    }
    return true;
}
ll solve(ll level)
{
    if (level == 8)
        return 1;
    ll tmp = 0;
    for (ll i = 0; i < 8; i++)
    {
        if (board[level][i] == '.' && check(level, i))
        {
            queens[level] = i;
            tmp += solve(level + 1);
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
    for (int i = 0; i < 8; i++)
    {
        cin >> board[i];
    }
    cout << solve(0) << endl;
    return 0;
}