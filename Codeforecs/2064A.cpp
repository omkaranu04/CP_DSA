#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if ((s[i] == '0' && s[i + 1] == '1') || (s[i] == '1' && s[i + 1] == '0'))
            cnt++;
    }
    if (s[0] == '1')
        cnt++;
    cout << cnt << endl;
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