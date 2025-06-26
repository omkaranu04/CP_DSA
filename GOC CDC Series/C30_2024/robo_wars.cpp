#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    stack<ll> st;
    for (ll i = 0; i < n; i++)
    {
        ll curr = a[i];
        bool alive = true;
        while (alive && !st.empty() && st.top() > 0 && curr < 0)
        {
            if (abs(curr) > abs(st.top()))
                st.pop();
            else if (abs(curr) == abs(st.top()))
            {
                st.pop();
                alive = false;
            }
            else
                alive = false;
        }
        if (alive)
            st.push(curr);
    }
    vector<ll> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
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