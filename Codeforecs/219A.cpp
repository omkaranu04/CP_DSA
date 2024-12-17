#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    vector<int> freq(26, 0);
    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i] - 97]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] % k != 0)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    vector<char> ans;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            for (int j = 0; j < freq[i] / k; j++)
            {
                ans.push_back((char)i + 97);
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            cout << ans[j];
        }
    }
    return 0;
}