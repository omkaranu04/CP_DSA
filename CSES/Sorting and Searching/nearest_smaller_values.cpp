#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    stack<pair<ll, ll>> st;
    for (ll i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first >= a[i])
            st.pop();
        if (st.empty())
            cout << 0 << " ";
        else
            cout << st.top().second + 1 << " ";
        st.push({a[i], i});
    }
    return 0;
}