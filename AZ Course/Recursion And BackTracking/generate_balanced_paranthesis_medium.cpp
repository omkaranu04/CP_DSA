#include <bits/stdc++.h>
using namespace std;
void recurse(int curr, int len, int open, int depth, string &s, int k)
{
    if (curr == len)
    {
        assert(open == 1);
        s += ")";
        if (depth == k)
            cout << s << "\n";
        s.pop_back();
        return;
    }
    if (open == 0)
    {
        s += "(";
        recurse(curr + 1, len, open + 1, max(depth, open + 1), s, k);
        s.pop_back();
    }
    else
    {
        int rem = len - curr + 1;
        if (rem > open)
        {
            s += "(";
            recurse(curr + 1, len, open + 1, max(depth, open + 1), s, k);
            s.pop_back();
        }
        s += ")";
        recurse(curr + 1, len, open - 1, max(depth, open - 1), s, k);
        s.pop_back();
    }
}
void solve()
{
    int n, k;
    cin >> n >> k;
    string s = "";
    recurse(1, n, 0, 0, s, k);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}