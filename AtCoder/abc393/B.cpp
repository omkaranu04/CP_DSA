#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    ll n = s.size(), ans = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            for (ll k = j + 1; k < n; k++)
            {
                if (s[i] == 'A' && s[j] == 'B' && s[k] == 'C' && (j - i == k - j))
                    ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}