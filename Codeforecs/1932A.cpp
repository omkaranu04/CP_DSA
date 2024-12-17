#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll coins = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '@')
                coins++;
            if (s[i] == '*' && s[i - 1] == '*')
                break;
        }
        cout << coins << endl;
    }
    return 0;
}