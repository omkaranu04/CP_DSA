#include <bits/stdc++.h>
using namespace std;
int n = 7, ans = 0;
bool visited[7][7];
string s;
void solve(int r, int c, int idx)
{
    if (r == n - 1 && c == 0)
    {
        ans += (idx == 48);
        return;
    }
    
    // TRAPS
    if (((r + 1 == n || (visited[r - 1][c] && visited[r + 1][c])) && c - 1 >= 0 && c + 1 < n && !visited[r][c - 1] && !visited[r][c + 1]) ||
        ((c + 1 == n || (visited[r][c - 1] && visited[r][c + 1])) && r - 1 >= 0 && r + 1 < n && !visited[r - 1][c] && !visited[r + 1][c]) ||
        ((r == 0 || (visited[r + 1][c] && visited[r - 1][c])) && c - 1 >= 0 && c + 1 < n && !visited[r][c - 1] && !visited[r][c + 1]) ||
        ((c == 0 || (visited[r][c + 1] && visited[r][c - 1])) && r - 1 >= 0 && r + 1 < n && !visited[r - 1][c] && !visited[r + 1][c]))
        return;

    visited[r][c] = true;
    if (s[idx] == 'U')
    {
        if (r - 1 >= 0 && !visited[r - 1][c])
        {
            idx++;
            solve(r - 1, c, idx);
            idx--;
        }
    }
    if (s[idx] == 'R')
    {
        if (c + 1 < n && !visited[r][c + 1])
        {
            idx++;
            solve(r, c + 1, idx);
            idx--;
        }
    }
    if (s[idx] == 'D')
    {
        if (r + 1 < n && !visited[r + 1][c])
        {
            idx++;
            solve(r + 1, c, idx);
            idx--;
        }
    }
    if (s[idx] == 'L')
    {
        if (c - 1 >= 0 && !visited[r][c - 1])
        {
            idx++;
            solve(r, c - 1, idx);
            idx--;
        }
    }
    if (s[idx] == '?')
    {
        if (r + 1 < n && !visited[r + 1][c])
        {
            idx++;
            solve(r + 1, c, idx);
            idx--;
        }
        if (c + 1 < n && !visited[r][c + 1])
        {
            idx++;
            solve(r, c + 1, idx);
            idx--;
        }
        if (r - 1 >= 0 && !visited[r - 1][c])
        {
            idx++;
            solve(r - 1, c, idx);
            idx--;
        }
        if (c - 1 >= 0 && !visited[r][c - 1])
        {
            idx++;
            solve(r, c - 1, idx);
            idx--;
        }
    }
    visited[r][c] = false;
    return;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    int idx = 0;
    solve(0, 0, idx);
    cout << ans << endl;
    return 0;
}