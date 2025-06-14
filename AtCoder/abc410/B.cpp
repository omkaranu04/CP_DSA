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
    ll n, q;
    cin >> n >> q;
    vector<ll> x(q);
    for (ll i = 0; i < q; i++)
        cin >> x[i];
    vector<ll> boxes(n, 0), ans(q);
    for (ll i = 0; i < q; i++)
    {
        if (x[i] >= 1)
        {
            boxes[x[i] - 1]++;
            ans[i] = x[i];
        }
        else
        {
            ll idx = *min_element(boxes.begin(), boxes.end());
            ll terget = 0;
            for (ll j = 0; j < n; j++)
            {
                if (boxes[j] == idx)
                {
                    terget = j;
                    break;
                }
            }
            boxes[terget]++;
            ans[i] = terget + 1;
        }
    }
    for (ll i = 0; i < q; i++)
        cout << ans[i] << " ";
    return 0;
}