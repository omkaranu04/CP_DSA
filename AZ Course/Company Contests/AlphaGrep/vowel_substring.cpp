#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll xmap(char x)
{
    if (x == 'a')
        return 0;
    else if (x == 'e')
        return 1;
    else if (x == 'i')
        return 2;
    else if (x == 'o')
        return 3;
    else if (x == 'u')
        return 4;
    else
        return 5;
}
bool isvowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
void solve()
{
    string s;
    cin >> s;
    ll n = s.length();
    ll i = 0, ans = 0;
    while (i < n)
    {
        while (i < n && !isvowel(s[i]))
            ++i;
        if (i == n)
            break;

        ll j = i;
        while (j < n && isvowel(s[j]))
            j++;

        ll L = i, R = i, distinct = 0;
        vector<ll> freq(5, 0);

        while (L < j)
        {
            while (R < j && distinct < 5)
            {
                ll id = xmap(s[R]);
                if (id < 5)
                {
                    if (freq[id] == 0)
                        distinct++;
                    freq[id]++;
                }
                R++;
            }

            if (distinct == 5)
                ans += j - R + 1;

            ll id = xmap(s[L]);
            if (id < 5)
            {
                --freq[id];
                if (freq[id] == 0)
                    --distinct;
            }
            ++L;
        }
        i = j;
    }
    cout << ans << endl;
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