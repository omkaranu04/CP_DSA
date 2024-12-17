#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool check(int i, string &s)
{
    if (i < 0 || i >= s.length() - 3)
        return false;
    if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0')
        return true;
    return false;
}
void solve()
{
    string s;
    cin >> s;
    int q;
    cin >> q;
    ll cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (check(i, s))
            cnt++;
    }
    while (q--)
    {
        ll i;
        char v;
        cin >> i >> v;
        i--;
        bool before = check(i, s) || check(i - 1, s) || check(i - 2, s) || check(i - 3, s);
        s[i] = v;
        bool after = check(i, s) || check(i - 1, s) || check(i - 2, s) || check(i - 3, s);
        cnt += after - before;
        cout << ((cnt) ? "YES\n" : "NO\n");
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}