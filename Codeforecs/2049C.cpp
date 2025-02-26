#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    // all 0 - indexed
    x--;
    y--;
    vector<ll> frds[n];
    for (int i = 0; i < n; i++)
    {
        frds[i].push_back((i + 1) % n);
        frds[i].push_back((i + n - 1) % n);
    }
    frds[x].push_back(y);
    frds[y].push_back(x);
    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto x : frds[i])
        {
            if (a[x] == a[i])
                a[x]++;
        }
    }
    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << "\n";
    return;
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