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
        int l = 0, r = n - 1, ans = n;
        while (s[l] != s[r] && ans > 0)
        {
            l++;
            r--;
            ans -= 2;
        }
        cout << ans << endl;
    }
    return 0;
}