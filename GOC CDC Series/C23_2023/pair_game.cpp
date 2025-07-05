#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll ans = 0;
    stack<char> st;
    for (auto c : s)
    {
        if (!st.empty() && st.top() == c)
        {
            st.pop();
            ans++;
        }
        else
            st.push(c);
    }
    cout << ((ans % k) + 1) << endl;
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