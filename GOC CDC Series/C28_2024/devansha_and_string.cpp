#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    stack<char> st;
    for (auto c : s)
    {
        if (st.empty() || st.top() != c)
            st.push(c);
        else
            st.pop();
    }
    string ans = "";
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans.length() << " " << ans << endl;
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