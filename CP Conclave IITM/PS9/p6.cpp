#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    long long int h;
    cin >> n >> h;
    vector<long long int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long int l = 1, r = 1e18, m, sum;
    while (l <= r)
    {
        m = (l + r) / 2;
        sum = m;
        for (int i = 0; i < n - 1; i++)
        {
            sum += min(m, a[i + 1] - a[i]);
        }
        if (sum >= h)
            r = m - 1;
        else
            l = m + 1;
    }
    cout << l << endl;
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}