#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] == '1' && s[s.length() - 1] == '1')
    {
        cout << "YES\n";
        return;
    }
    else if (s.find("111") != string::npos) // to check if "111" is a substring of s
    {
        cout << "YES\n";
        return;
    }
    else if ((s[0] == '1' || s[s.length() - 1] == '1') && (s.find("11") != string::npos))
    {
        cout << "YES\n";
        return;
    }
    else
    {
        ll count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s.substr(i, 2) == "11")
            {
                count++;
                i++;
            }
        }
        if (count >= 2)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}