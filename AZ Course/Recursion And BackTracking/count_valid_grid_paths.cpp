#include <bits/stdc++.h>
using namespace std;
const int n = 7;
bool visited[n][n];
int ans = 0;
string s;
void move(int r, int c, int count)
{
    if (r == n - 1 && c == 0)
    {
        ans += (count == n * n - 1);
        return;
    }
    if (((r + 1 == n || (visited[r - 1][c] && visited[r + 1][c])) && c - 1 >= 0 && c + 1 < n && !visited[r][c - 1] && !visited[r][c + 1]) ||
        ((c + 1 == n || (visited[r][c - 1] && visited[r][c + 1])) && r - 1 >= 0 && r + 1 < n && !visited[r - 1][c] && !visited[r + 1][c]) ||
        ((r == 0 || (visited[r + 1][c] && visited[r - 1][c])) && c - 1 >= 0 && c + 1 < n && !visited[r][c - 1] && !visited[r][c + 1]) ||
        ((c == 0 || (visited[r][c + 1] && visited[r][c - 1])) && r - 1 >= 0 && r + 1 < n && !visited[r - 1][c] && !visited[r + 1][c]))
        return;

    visited[r][c] = true;

    if (s[count] == 'U')
    {
        if (r - 1 >= 0 && !visited[r - 1][c])
        {
            count++;
            move(r - 1, c, count);
            count--;
        }
    }
    else if (s[count] == 'R')
    {
        if (c + 1 < n && !visited[r][c + 1])
        {
            count++;
            move(r, c + 1, count);
            count--;
        }
    }
    else if (s[count] == 'D')
    {
        if (r + 1 < n && !visited[r + 1][c])
        {
            count++;
            move(r + 1, c, count);
            count--;
        }
    }
    else if (s[count] == 'L')
    {
        if (c - 1 >= 0 && !visited[r][c - 1])
        {
            count++;
            move(r, c - 1, count);
            count--;
        }
    }
    else if (s[count] == '?')
    {
        if (r + 1 < n && !visited[r + 1][c])
        {
            count++;
            move(r + 1, c, count);
            count--;
        }
        if (c + 1 < n && !visited[r][c + 1])
        {
            count++;
            move(r, c + 1, count);
            count--;
        }
        if (r - 1 >= 0 && !visited[r - 1][c])
        {
            count++;
            move(r - 1, c, count);
            count--;
        }
        if (c - 1 >= 0 && !visited[r][c - 1])
        {
            count++;
            move(r, c - 1, count);
            count--;
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
    int count = 0;
    move(0, 0, count);
    cout << ans << "\n";
    return 0;
}