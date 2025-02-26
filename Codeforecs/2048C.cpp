#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    string s;
    cin >> s;
    ll b_ = 0, st = 0;
    ll l, r;
    for (ll i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            st = i;
            b_ = s.length() - i;
            break;
        }
    }
    if (b_ == 0)
    {
        cout << 1 << " " << s.length() << " " << 1 << " " << 1 << endl;
        return;
    }
    else
    {
        l = 0;
        r = 0;
        string ans = s;
        for (ll i = 0; i + b_ <= s.length(); i++)
        {
            string curr = s;
            for (ll j = i; j < i + b_; j++)
            {
                curr[j - i + st] = ((curr[j - i + st] - '0') ^ (s[j] - '0')) + '0';
            }
            if (curr > ans)
            {
                ans = curr;
                l = i;
                r = i + b_ - 1;
            }
        }
    }
    cout << 1 << " " << s.length() << " " << l + 1 << " " << r + 1 << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}