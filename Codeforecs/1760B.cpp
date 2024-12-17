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
        sort(s.begin(), s.end());
        ll ans = s[n - 1] - 'a' + 1;
        cout << ans << endl;
    }
    return 0;
}