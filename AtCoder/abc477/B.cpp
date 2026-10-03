#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, d;
    cin >> n >> d;
    vector<ll> x(n);
    for (ll i = 0; i < n; i++)
        cin >> x[i];
    vector<ll> ans;
    for (ll i = 0; i < n; i++)
    {
        bool flag = true;
        for (ll j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            if (llabs(x[i] - x[j]) < d)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            ans.push_back(i + 1);
    }
    cout << ans.size() << endl;
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
    return 0;
}