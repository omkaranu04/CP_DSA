#include <bits/stdc++.h>
using namespace std;
#define ll long long int
/*
    1 2 3
    4 5 6
    7 8 9
*/
ll skip[10][10]; // stores midpoint for cross overs
bool visited[10];
ll n;
ll rec(ll curr, ll left)
{
    if(left == 0) return 1;
    visited[curr] = true;
    ll ans = 0;
    for(ll next = 1; next <= 9; next++)
    {
        if(!visited[next] && (skip[curr][next] == 0 || visited[skip[curr][next]])) ans += rec(next, left - 1);
    }
    visited[curr] = false;
    return ans;
}
void solve()
{
    cin >> n;

    memset(skip, 0, sizeof(skip));
    memset(visited, false, sizeof(visited));
    skip[1][3] = skip[3][1] = 2;
    skip[1][7] = skip[7][1] = 4;
    skip[1][9] = skip[9][1] = 5;
    skip[2][8] = skip[8][2] = 5;
    skip[3][7] = skip[7][3] = 5; 
    skip[3][9] = skip[9][3] = 6;
    skip[4][6] = skip[6][4] = 5;
    skip[7][9] = skip[9][7] = 8;

    ll ans = 0;
    ans += rec(1, n - 1) * 4;
    ans += rec(2, n - 1) * 4;
    ans += rec(5, n - 1);

    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}