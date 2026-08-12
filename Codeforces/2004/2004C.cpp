#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int j = n - 2;
    while (k > 0 && j >= 0)
    {
        int diff = a[j + 1] - a[j];
        int increase = min(diff, k);
        a[j] += increase;
        k -= increase;
        if (increase == diff)
            j -= 2;
        else
            break;
    }

    ll sum = 0;
    int i;
    for (i = n - 1; i >= 1; i -= 2)
    {
        sum += (a[i] - a[i - 1]);
    }
    if (i == 0)
        sum += a[i];
    cout << sum << endl;
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