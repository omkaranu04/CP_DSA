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
    string s;
    cin >> s;
    string ans = "";
    for (ll i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '.')
            break;
        else
            ans.push_back(s[i]);
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}