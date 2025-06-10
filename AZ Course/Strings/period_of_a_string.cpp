#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vector<ll> kmp(n + 1);
        kmp[0] = -1;
        ll i = 0, j = -1;
        while (i < n)
        {
            while (j != -1 && s[i] != s[j])
                j = kmp[j];
            j++, i++;
            kmp[i] = j;
        }
        cout << "Test case #" << testcase << endl;
        for (ll len = 2; len <= n; len++)
        {
            ll period = len - kmp[len];
            if (kmp[len] > 0 && len % period == 0)
            {
                ll k = len / period;
                if (k > 1)
                    cout << len << " " << k << endl;
            }
        }
        cout << endl;
    }
    return 0;
}