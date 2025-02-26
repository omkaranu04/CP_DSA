#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    ll ans = 0;
    s = " " + s;
    for (ll i = 1; i <= n - 2; i++)
    {
        if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')
            ans++;
    }
    while (q--)
    {
        ll idx;
        char c;
        cin >> idx >> c;
        ll ans1 = 0;
        for (ll i = idx - 2; i <= idx + 2; i++)
        {
            if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')
                ans1++;
        }
        s[idx] = c;
        ll ans2 = 0;
        for (ll i = idx - 2; i <= idx + 2; i++)
        {
            if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')
                ans2++;
        }
        ans -= ans1;
        ans += ans2;
        cout << ans << endl;
    }
    return 0;
}