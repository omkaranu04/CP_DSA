#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll countpattern(string &s, char A, char B)
{
    ll cntA = 0, cntAA = 0, cntAAB = 0, ans = 0;
    for (auto c : s)
    {
        if (c == A)
        {
            cntAA += cntA;
            cntA++;
        }
        else
        {
            ans += cntAAB;
            cntAAB += cntAA;
        }
    }
    return ans;
}
void solve()
{
    ll N;
    cin >> N;
    string s;
    cin >> s;
    if (N < 4)
    {
        cout << 0 << endl;
        return;
    }
    ll ans = countpattern(s, 'V', 'M');
    ans += countpattern(s, 'M', 'V');
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