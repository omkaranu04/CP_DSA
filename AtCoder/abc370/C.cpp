#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, t;
    cin >> s >> t;
    vector<string> x;
    while (s != t)
    {
        string next(s.size(), 'z');
        for (ll i = 0; i < s.size(); i++)
        {
            if (s[i] != t[i])
            {
                string temp = s;
                temp[i] = t[i];
                next = min(next, temp);
            }
        }
        x.push_back(next);
        s = next;
    }
    cout << x.size() << endl;
    for (auto i : x)
    {
        cout << i << endl;
    }
    return 0;
}