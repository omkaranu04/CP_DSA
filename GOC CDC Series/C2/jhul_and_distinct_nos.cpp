#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    set<ll> s;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    map<ll, ll> mp;
    ll j = -1, i = 0, cnt = 0, ans = n;
    while (i < n)
    {
        while (j + 1 < n && cnt < s.size())
        {
            j++;
            mp[a[j]]++;
            if (mp[a[j]] == 1)
                cnt++;
        }
        if (cnt == s.size())
            ans = min(ans, j - i + 1);
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
