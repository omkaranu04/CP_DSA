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
    map<char, int> mp;
    for (auto i : s)
    {
        mp[i]++;
    }
    int odd = 0;
    char odd_char;
    for (auto i : mp)
    {
        if (i.second % 2 != 0)
        {
            odd++;
            odd_char = i.first;
        }
    }
    if (odd > 1)
    {
        cout << "NO SOLUTION";
    }
    else
    {
        string ans = "";
        for (auto i : mp)
        {
            if (i.second % 2 == 0)
            {
                for (int j = 0; j < i.second / 2; j++)
                {
                    ans += i.first;
                }
            }
        }
        cout << ans;
        if (odd == 1)
        {
            for (int i = 0; i < mp[odd_char]; i++)
            {
                cout << odd_char;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
    return 0;
}