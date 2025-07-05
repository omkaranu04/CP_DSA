#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, t;
    cin >> s >> t;
    unordered_set<char> tset(t.begin(), t.end());
    bool found = true;
    for (ll i = 1; i < s.length(); i++)
    {
        if (isupper(s[i]))
        {
            if (tset.find(s[i - 1]) == tset.end())
            {
                found = false;
                break;
            }
        }
    }
    if (found)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}