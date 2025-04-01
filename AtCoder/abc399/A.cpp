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
    string s, t;
    cin >> n;
    cin >> s;
    cin >> t;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}