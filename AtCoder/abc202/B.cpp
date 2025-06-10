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
    reverse(s.begin(), s.end());
    for (ll i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
            cout << '0';
        else if (s[i] == '1')
            cout << '1';
        else if (s[i] == '8')
            cout << '8';
        else if (s[i] == '6')
            cout << '9';
        else if (s[i] == '9')
            cout << '6';
    }
    return 0;
}