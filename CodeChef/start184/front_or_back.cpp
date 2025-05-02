#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 998244353;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<ll> temp(n, -1);
    ll ans = 1;
    for (int i = 0; i < n; i++)
    {
        ll front = arr[i], back = n - arr[i] - 1;
        if (temp[front] == -1 && temp[back] == -1)
        {
            if (front != back)
            {
                ans = (ans * 2) % mod;
                temp[front] = 1;
            }
            else
                temp[front] = 1;
        }
        else if (temp[front] == -1 && temp[back] != -1)
            temp[front] = 1;
        else if (temp[front] != -1 && temp[back] == -1)
            temp[back] = 1;
        else
        {
            ans = ans * 0;
            break;
        }
    }
    cout << ans % mod << endl;
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