#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    multiset<ll> st;
    for (ll i = 0; i < n; i++)
    {
        ll l, r;
        cin >> l >> r;
        auto it = st.upper_bound(r);
        if (it != st.end())
            st.erase(it);
        st.insert(l);
        cout << st.size() << " ";
    }
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