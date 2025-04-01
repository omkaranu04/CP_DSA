#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    stack<ll> st;
    for (ll i = 0; i < 100; i++)
        st.push(0);
    ll q;
    cin >> q;
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll x;
            cin >> x;
            st.push(x);
        }
        else
        {
            cout << st.top() << endl;
            st.pop();
        }
    }
    return 0;
}