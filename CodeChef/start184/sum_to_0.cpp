#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> res;
    if (n % 2 == 0)
    {
        for (int i = 0; i < n / 2; i++)
        {
            res.push_back(1);
            res.push_back(-1);
        }
    }
    else
    {
        res.push_back(1);
        res.push_back(2);
        res.push_back(-3);
        n = n - 3;
        for (int i = 0; i < n / 2; i++)
        {
            res.push_back(1);
            res.push_back(-1);
        }
    }
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << (i + 1 == res.size() ? '\n' : ' ');
    }
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