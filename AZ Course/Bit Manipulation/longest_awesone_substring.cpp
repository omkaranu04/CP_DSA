#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
int longestAwesome(string s)
{
    unordered_map<int, int> mp;
    int mask = 0, ans = 0;
    mp[mask] = -1;
    for (int i = 0; i < s.size(); i++)
    {
        int digit = s[i] - '0';
        mask ^= (1 << digit);
        if (mp.count(mask))
            ans = max(ans, i - mp[mask]);
        else
            mp[mask] = i;

        for (int j = 0; j < 10; j++)
        {
            int maskl = mask ^ (1 << j);
            if (mp.count(maskl))
                ans = max(ans, i - mp[maskl]);
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    ll ans = longestAwesome(s);
    cout << ans << endl;
    return 0;
}