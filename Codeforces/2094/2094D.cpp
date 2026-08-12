#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    string p, s;
    cin >> p >> s;
    ll i = 0, j = 0;
    while (i < p.size() && j < s.size())
    {
        char pf = p[i];
        ll cntp = 0;
        while (i < p.size() && p[i] == pf)
        {
            cntp++;
            i++;
        }
        if (s[j] != pf)
        {
            cout << "NO\n";
            return;
        }
        ll cnts = 0;
        while (j < s.size() && s[j] == pf)
        {
            cnts++;
            j++;
        }
        if (cnts < cntp || cnts > 2 * cntp)
        {
            cout << "NO\n";
            return;
        }
    }
    if (i == p.size() && j == s.size())
        cout << "YES\n";
    else
        cout << "NO\n";
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