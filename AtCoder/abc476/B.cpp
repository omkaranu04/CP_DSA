#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    if (s.length() != t.length())
    {
        cout << "No\n";
        return 0;
    }
    for (ll i = 0; i < s.length(); i++)
    {
        if (t[i] == '*')
            continue;
        if (s[i] != t[i])
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}