#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<int> price, pages;
vector<vector<int>> dp;
int rec(int index, int money_remaining)
{
    if (index >= n || money_remaining == 0)
        return 0;

    if (dp[index][money_remaining] != -1)
        return dp[index][money_remaining];

    int take = 0, not_take = 0;
    not_take = rec(index + 1, money_remaining);
    if (money_remaining >= price[index])
        take = pages[index] + rec(index + 1, money_remaining - price[index]);

    return dp[index][money_remaining] = max(take, not_take);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> x;
    price.resize(n);
    pages.resize(n);
    dp.resize(n + 1, vector<int>(x + 1, -1));
    for (int i = 0; i < n; i++)
        cin >> price[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];
    int ans = rec(0, x);
    cout << ans << endl;
    return 0;
}