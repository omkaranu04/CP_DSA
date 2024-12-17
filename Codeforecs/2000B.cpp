#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{ 
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    bool flag = true;
    vector<bool> seated(n + 1, false);
    seated[a[1]] = true;
    for (int i = 2; i <= n; i++)
    {
        if (!((a[i] - 1 >= 0 && a[i] - 1 <= n && seated[a[i] - 1]) || (a[i] + 1 >= 0 && a[i] + 1 <= n && seated[a[i] + 1])))
            flag = false;
        seated[a[i]] = true;
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}