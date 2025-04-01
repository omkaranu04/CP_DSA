#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string t, s;
    cin >> t >> s;
    string str = s + "#" + t;
    ll n = str.size();
    ll m = s.size();
    vector<ll> kmp(n + 1);
    kmp[0] = -1;
    ll i = 0, j = -1;
    while (i < n)
    {
        while (j != -1 && str[i] != str[j])
            j = kmp[j];
        j++, i++;
        kmp[i] = j;
    }
    // cout << str << endl;
    // for (ll i = 0; i <= n; i++)
    // {
    //     cout << kmp[i] << " ";
    // }
    // cout << endl;
    ll ans = 0;
    for (ll i = m + 1; i <= n; i++)
    {
        if (kmp[i] == m)
            ans++;
    }
    cout << ans << endl;
    return 0;
}