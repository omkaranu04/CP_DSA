#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ll Q;
    cin >> Q;
    vector<vector<ll>> a;
    ll offset = 0, itr = 0;
    while (Q--)
    {
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll l;
            cin >> l;
            ll temp = ((a.size() == 0) ? 0 : a.back()[1]);
            a.push_back({temp, temp + l});
        }
        else if (type == 2)
        {
            offset += (a[itr][1] - a[itr][0]);
            itr++;
        }
        else if (type == 3)
        {
            ll k;
            cin >> k;
            // cout << "ans : ";
            cout << a[itr + k - 1][0] - offset << endl;
        }
    }
    return 0;
}