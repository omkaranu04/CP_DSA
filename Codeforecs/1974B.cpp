#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string b;
        cin >> b;
        vector<ll> freq(26, 0);
        for (ll i = 0; i < b.length(); i++)
        {
            freq[b[i] - 'a']++;
        }
        vector<char> unique;
        for (ll i = 0; i < 26; i++)
        {
            if (freq[i])
                unique.push_back((char)(i + 97));
        }
        sort(unique.begin(), unique.end());
        unordered_map<char, char> decode_map;
        int m = unique.size();
        for (int i = 0; i < m; i++)
        {
            decode_map[unique[i]] = unique[m - i - 1];
        }
        string ans;
        for (char ch : b)
        {
            ans += decode_map[ch];
        }
        cout << ans << endl;
    }
    return 0;
}