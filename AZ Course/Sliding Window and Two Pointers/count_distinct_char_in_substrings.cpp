#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    string s;
    cin >> n >> s;
    ll tot = (n * (n + 1)) / 2, ans = 0;
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        ll tmp = 0, i = 0;
        while (i < n)
        {
            if (s[i] == ch)
            {
                i++;
                continue;
            }
            ll j = i;
            while (j < n && s[j] != ch)
                j++;
            ll len = j - i;
            tmp += (len * (len + 1)) / 2;
            i = j;
        }
        ans += (tot - tmp);
    }
    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}