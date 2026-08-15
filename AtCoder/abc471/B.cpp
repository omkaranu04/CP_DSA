#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    map<string, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (char &c : s)
        {
            c = tolower(c);
        }
        mp[s]++;
    }
    ll cnt = -1;
    string ans = "";
    for (auto x : mp)
    {
        if (x.second > cnt)
        {
            ans = x.first;
            cnt = x.second;
        }
    }
    cout << cnt << endl;
    return 0;
}