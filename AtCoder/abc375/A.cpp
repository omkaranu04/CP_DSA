#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    for (ll i = 0; i < n - 2; i++)
    {
        if (s[i] == '#' && s[i + 1] == '.' && s[i + 2] == '#')
            ans++;
    }
    cout << ans << endl;
    return 0;
}