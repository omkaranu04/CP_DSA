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

// #include <bits/stdc++.h>
// using namespace std;

// static const int INF_NEG = -1000000000;
// int n, k;
// string s;
// vector<int> a;

// // dp[i][rem][last] = max wins from games i..n-1
// //   if you have rem changes left, and your previous move was `last`.
// // last ∈ {0=P,1=R,2=S}
// int dp[1001][1001][3];
// // ch[i][rem][last] = which move (0/1/2) gave that optimum,
// //   so that we can rebuild lexicographically smallest.
// int ch[1001][1001][3];

// // does my move `me` beat opponent's move `you`?
// bool win(int me, int you)
// {
//     return (me == 0 && you == 1) || (me == 1 && you == 2) || (me == 2 && you == 0);
// }

// // Recursion for i=1..n-1
// int rec(int i, int rem, int last)
// {
//     if (rem < 0)
//         return INF_NEG;
//     if (i == n)
//         return 0;
//     int &ans = dp[i][rem][last];
//     if (ans != -1)
//         return ans;

//     ans = INF_NEG;
//     int bestMv = 3;
//     // try all 3 current moves
//     for (int mv = 0; mv < 3; mv++)
//     {
//         int cost = (mv == last ? 0 : 1);
//         int w = win(mv, a[i]) ? 1 : 0;
//         int tmp = w + rec(i + 1, rem - cost, mv);
//         if (tmp > ans || (tmp == ans && mv < bestMv))
//         {
//             ans = tmp;
//             bestMv = mv;
//         }
//     }
//     ch[i][rem][last] = bestMv;
//     return ans;
// }

// // Build answer from i=1..n-1
// void build(int i, int rem, int last, string &res)
// {
//     if (i == n)
//         return;
//     int mv = ch[i][rem][last];
//     res.push_back("PRS"[mv]);
//     int cost = (mv == last ? 0 : 1);
//     build(i + 1, rem - cost, mv, res);
// }

// void solve()
// {
//     cin >> n >> k >> s;
//     a.resize(n);
//     for (int i = 0; i < n; i++)
//     {
//         if (s[i] == 'P')
//             a[i] = 0;
//         else if (s[i] == 'R')
//             a[i] = 1;
//         else
//             a[i] = 2;
//     }

//     // init dp & ch
//     for (int i = 0; i <= n; i++)
//     {
//         for (int r = 0; r <= k; r++)
//         {
//             for (int last = 0; last < 3; last++)
//             {
//                 dp[i][r][last] = -1;
//                 ch[i][r][last] = 3;
//             }
//         }
//     }

//     // peel off i=0 by brute forcing your first move
//     int bestWins = INF_NEG, bestFirst = 3;
//     for (int first = 0; first < 3; first++)
//     {
//         int w0 = win(first, a[0]) ? 1 : 0;
//         int cur = w0 + rec(1, k, first);
//         if (cur > bestWins || (cur == bestWins && first < bestFirst))
//         {
//             bestWins = cur;
//             bestFirst = first;
//         }
//     }

//     // output max wins
//     cout << bestWins << "\n";

//     // build the string
//     string res;
//     // move 0
//     res.push_back("PRS"[bestFirst]);
//     // the rest
//     int w0 = win(bestFirst, a[0]) ? 1 : 0;
//     build(1, k, bestFirst, res);

//     cout << res << "\n";
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T;
//     cin >> T;
//     while (T--)
//     {
//         solve();
//     }
//     return 0;
// }
