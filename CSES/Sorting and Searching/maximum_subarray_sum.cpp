#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll ans = a[0], sum = a[0];
    for (int i = 1; i < n; i++)
    {
        sum = max(a[i], sum + a[i]);
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}