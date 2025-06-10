#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    string s, t;
    cin >> s;
    n = s.length();
    vector<ll> kmp(n + 1);
    kmp[0] = -1;
    ll i = 0, j = -1;
    while (i < n)
    {
        while (j != -1 && s[i] != s[j])
            j = kmp[j];
        i++, j++;
        kmp[i] = j;
    }
    vector<bool> occur(n + 1, false);
    for (i = 1; i < n; i++)
        occur[kmp[i]] = true;
    ll len = kmp[n];
    while (len > 0 && !occur[len])
        len = kmp[len];
    if (len <= 0)
        cout << "-1\n";
    else
        cout << s.substr(0, len) << endl;
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