#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    ll n = s.size();
    if (n % 2)
    {
        cout << "No\n";
        return 0;
    }
    unordered_map<char, ll> mp;
    for (auto i : s)
    {
        mp[i]++;
    }
    for (auto i : mp)
    {
        if (i.second != 2)
        {
            cout << "No\n";
            return 0;
        }
    }
    for (int i = 1; i <= n / 2; i++)
    {
        if (s[2 * i - 1] != s[2 * i - 2])
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}