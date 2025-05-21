#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll j = -1, i = 0, cnt = 0, ans = 0;
    map<ll, ll> mp;
    while (i < n)
    {
        while (j + 1 < n && (cnt + (mp[a[j + 1]] == 0) == (j + 1) - i + 1))
        {
            j++;
            mp[a[j]]++;
            if (mp[a[j]] == 1)
                cnt++;
        }
        if (cnt == j - i + 1)
            ans += (j - i + 1);
        if (i > j)
        {
            i++;
            j = i - 1;
        }
        else
        {
            mp[a[i]]--;
            if (mp[a[i]] == 0)
                cnt--;
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}