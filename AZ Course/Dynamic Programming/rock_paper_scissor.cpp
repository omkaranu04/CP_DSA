#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
vector<int> a;
string res;
int dp[1001][1001][3];
// let me decide the first move
// 0 -> P, 1 -> R, 2 -> S
bool result(int mov1, int mov2) // mov1 be mine
{
    return (mov1 == 0 && mov2 == 1) || (mov1 == 1 && mov2 == 2) || (mov1 == 2 && mov2 == 0);
}
int rec(int idx, int ch, int prev_mov)
{
    if (ch < 0)
        return -1e9;
    if (idx == n)
        return 0;

    if (dp[idx][ch][prev_mov] != -2)
        return dp[idx][ch][prev_mov];

    int ans = -1e9;
    for (int curr_mov = 0; curr_mov < 3; curr_mov++)
    {
        ans = max(ans, (result(curr_mov, a[idx]) ? 1 : 0) + rec(idx + 1, ch - (curr_mov != prev_mov), curr_mov));
    }

    return dp[idx][ch][prev_mov] = ans;
}
void gen_string(int idx, int ch, int prev_mov, int ans) // here also let me dicide the first move
{
    if (idx == n)
        return;
    for (int curr_mov = 0; curr_mov < 3; curr_mov++)
    {
        int tx = (result(curr_mov, a[idx]) ? 1 : 0);
        int temp = rec(idx + 1, ch - ((curr_mov != prev_mov) ? 1 : 0), curr_mov) + tx;
        if (temp == ans)
        {
            res.push_back("PRS"[curr_mov]);
            gen_string(idx + 1, ch - ((curr_mov != prev_mov) ? 1 : 0), curr_mov, ans - tx);
            return;
        }
    }
}
void solve()
{
    cin >> n >> k;
    cin >> s;
    a.resize(n);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int l = 0; l < 3; l++)
            {
                dp[i][j][l] = -2;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'P')
            a[i] = 0;
        if (s[i] == 'R')
            a[i] = 1;
        if (s[i] == 'S')
            a[i] = 2;
    }

    int ans = -1e9;
    for (int i = 0; i < 3; i++)
    {
        ans = max(ans, rec(1, k, i) + (result(i, a[0]) ? 1 : 0));
    }
    // cout << "ans : ";
    cout << ans << endl;

    res = "";
    for (int i = 0; i < 3; i++)
    {
        if (ans == (rec(1, k, i) + (result(i, a[0]) ? 1 : 0)))
        {
            res.push_back("PRS"[i]);
            gen_string(1, k, i, ans - (result(i, a[0]) ? 1 : 0));
            break;
        }
    }
    // cout << "res : ";
    cout << res << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}