#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        unordered_map<char, ll> hash;
        ll index = -1;
        hash[s[0]]++;
        for (int i = 1; i < s.length(); i++)
        {
            hash[s[i]]++;
            if (s[i] == s[i - 1])
                index = i;
        }
        if (index == -1)
        {
            char to_insert = 'a';
            while (hash.count(to_insert))
                to_insert++;
            string r = s + to_insert;
            cout << r << endl;
        }
        else
        {
            char to_insert = 'a';
            while (to_insert == s[index] || hash.count(to_insert))
                to_insert++;
            string x = s.substr(0, index) + to_insert + s.substr(index);
            cout << x << endl;
        }
    }
    return 0;
}