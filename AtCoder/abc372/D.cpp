#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> h(n + 1), ans(n + 1, 0);
    stack<ll> st;
    for (ll i = 1; i <= n; i++)
        cin >> h[i];
    for (ll i = n - 1; i >= 1; i--)
    {
        while (!st.empty() && h[st.top()] < h[i + 1])
            st.pop();
        st.push(i + 1);
        ans[i] = st.size();
    }
    for (ll i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}