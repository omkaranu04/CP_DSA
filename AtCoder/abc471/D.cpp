#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll q, v;
    cin >> q >> v;
    priority_queue<pair<ll, ll>> pq;
    ll bfull = 0;
    while (q--)
    {
        ll x, t, w;
        cin >> x >> t;
        if (x == 1)
        {
            cin >> w;
            if (w == v)
                bfull++;
            else
                pq.push({w - t, t});
        }
        else
        {
            if (!pq.empty())
            {
                ll top_pert = pq.top().first;
                if (top_pert + t >= v)
                {
                    pq.pop();
                    cout << v << endl;
                }
                else if (bfull > 0)
                {
                    cout << v << endl;
                    bfull--;
                }
                else
                {
                    pq.pop();
                    cout << top_pert + t << endl;
                }
            }
            else if (bfull > 0)
            {
                cout << v << endl;
                bfull--;
            }
            else
            {
                cout << "-1" << endl;
            }
        }
    }
    return 0;
}