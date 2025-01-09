#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    if (sum % 2)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<ll> a, b;
    vector<bool> vis(n + 1, false);
    ll target1 = sum / 2;
    ll target2 = sum / 2;
    for (int i = n; i >= 1; i--)
    {
        if (target1 >= i && !vis[i])
        {
            a.push_back(i);
            vis[i] = true;
            target1 -= i;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (target2 >= i && !vis[i])
        {
            b.push_back(i);
            vis[i] = true;
            target2 -= i;
        }
    }
    cout << a.size() << endl;
    for (auto x : a)
        cout << x << " ";
    cout << endl;
    cout << b.size() << endl;
    for (auto x : b)
        cout << x << " ";
    cout << endl;
    return 0;
}