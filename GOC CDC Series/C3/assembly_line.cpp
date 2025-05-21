#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n;
    cin >> n;
    vector<ll> h(n + 1), tall(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        cin >> h[i];
    stack<ll> st;
    for (ll i = 1; i <= n; i++)
    {
        while (!st.empty() && h[st.top()] < h[i])
            st.pop();
        if (!st.empty())
            tall[i] = st.top();
        st.push(i);
    }
    // for(ll i=1;i<=n;i++) cout<<tall[i]<<" ";
    // cout<<endl;
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
        ans += (i - tall[i] - 1);
    cout << ans << endl;
    return 0;
}
