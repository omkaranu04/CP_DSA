#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, q;
    cin >> n >> q;
    vector<ll> place(n + 1), nests(n + 1, 1);
    for (ll i = 1; i <= n; i++)
        place[i] = i;
    ll multi = 0;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            ll p, h;
            cin >> p >> h;
            ll curr = place[p];
            nests[curr]--;
            if (nests[curr] == 1)
                multi--;
            nests[h]++;
            if (nests[h] == 2)
                multi++;
            place[p] = h;
        }
        else if (t == 2)
        {
            // cout << "ans: ";
            cout << multi << endl;
        }
    }
    return 0;
}