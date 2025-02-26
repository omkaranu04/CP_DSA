#include <bits/stdc++.h>
using namespace std;

set<string> generate(string s)
{
    set<string> ans;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            string temp = s;
            reverse(temp.begin() + i, temp.begin() + j + 1);
            ans.insert(temp);
        }
    }
    return ans;
}

void solve()
{
    string s, t;
    cin >> s >> t;

    set<string> s2, t2;

    s2.insert(s);
    set<string> first = generate(s);
    for (auto i : first)
    {
        set<string> second = generate(i);
        s2.insert(second.begin(), second.end());
    }

    t2.insert(t);
    set<string> first_t = generate(t);
    for (auto i : first_t)
    {
        set<string> second = generate(i);
        t2.insert(second.begin(), second.end());
    }

    for (auto str : s2)
    {
        if (t2.find(str) != t2.end())
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
