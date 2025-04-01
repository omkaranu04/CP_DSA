#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n, k;
vector<ll> r;
void gen(ll idx, vector<ll> &curr, ll currsum)
{
    if (idx == n)
    {
        if (currsum % k == 0)
        {
            for (auto x : curr)
                cout << x << " ";
            cout << endl;
        }
        return;
    }

    for (ll i = 1; i <= r[idx]; i++)
    {
        curr.push_back(i);
        gen(idx + 1, curr, currsum + i);
        curr.pop_back();
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    r.resize(n);
    for (ll i = 0; i < n; i++)
        cin >> r[i];

    vector<ll> curr;
    gen(0, curr, 0);
    return 0;
}