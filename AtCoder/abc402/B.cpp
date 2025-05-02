#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    deque<ll> dq;
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
            dq.push_back(x);
        }
        if (t == 2)
        {
            ll temp = dq.front();
            dq.pop_front();
            cout << temp << endl;
        }
    }
    return 0;
}