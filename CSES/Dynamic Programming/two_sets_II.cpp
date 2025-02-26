#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
int binExp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % M;
        }
        a = (a * 1LL * a) % M;
        b >>= 1;
    }
    return ans;
}

int dp[501][63000];

int findWays(int x, int sum_left)
{
    if (sum_left == 0)
        return 1;
    if (x <= 0)
        return 0;

    if (dp[x][sum_left] != -1)
        return dp[x][sum_left];

    int notPick = findWays(x - 1, sum_left);
    int pick = 0;
    if (sum_left >= x)
        pick = findWays(x - 1, sum_left - x);

    return dp[x][sum_left] = (notPick + pick) % M;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    ll sum = 1LL * n * (n + 1) / 2;

    if (sum % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    int target = sum / 2;

    memset(dp, -1, sizeof(dp));

    int ans = findWays(n, target);

    cout << (ans * 1LL * binExp(2, M - 2)) % M << endl;

    return 0;
}