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
    vector<string> dict;
    for (ll i = 0; i < 26; i++)
    {
        for (ll j = 0; j < 26; j++)
        {
            if (j == i)
                continue;
            string s = "";
            s += (char)(i + 'a');
            s += (char)(j + 'a');
            dict.push_back(s);
        }
    }
    // for (auto x : dict)
    //     cout << x << " ";
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        auto it = lower_bound(dict.begin(), dict.end(), s) - dict.begin();
        cout << it + 1 << endl;
    }
    return 0;
}