#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void recurse(ll curr, ll len, ll open, string &s)
{
    if (curr == len)
    {
        assert(open == 1);
        s += ")";
        cout << s << "\n";
        s.pop_back();
        return;
    }
    if (open == 0)
    {
        s += "(";
        recurse(curr + 1, len, open + 1, s);
        s.pop_back();
    }
    else
    {
        ll rem = len - curr + 1;
        if (rem > open)
        {
            s += "(";
            recurse(curr + 1, len, open + 1, s);
            s.pop_back();
        }
        s += ")";
        recurse(curr + 1, len, open - 1, s);
        s.pop_back();
    }
}
void solve()
{
    ll n;
    cin >> n;
    string s = "";
    recurse(1, n, 0, s);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}