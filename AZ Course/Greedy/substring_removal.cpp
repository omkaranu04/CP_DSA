#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    string s;
    ll x, y;
    cin >> s >> x >> y;
    string first = "ab";
    string second = "ba";
    if (y > x)
    {
        swap(x, y);
        swap(first, second);
    }
    ll ans = 0;
    stack<char> st;
    st.push(s[0]);
    for (ll i = 1; i < s.length(); i++)
    {
        if (!st.empty() && st.top() == first[0] && s[i] == first[1])
        {
            st.pop();
            ans += x;
        }
        else
        {
            st.push(s[i]);
        }
    }
    string backup;
    while (!st.empty())
    {
        backup += st.top();
        st.pop();
    }
    reverse(backup.begin(), backup.end());
    // cout << backup << endl;
    st.push(backup[0]);
    for (ll i = 1; i < backup.length(); i++)
    {
        if (!st.empty() && st.top() == second[0] && backup[i] == second[1])
        {
            st.pop();
            ans += y;
        }
        else
        {
            st.push(backup[i]);
        }
    }
    cout << ans << "\n";
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}