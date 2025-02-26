#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    bool changed = true;
    while (changed)
    {
        changed = false;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] != '0' && (s[i] - '0') > (s[i - 1] - '0') + 1)
            {
                int j = i;
                while (j > 0 && (s[j] - '0') > (s[j - 1] - '0') + 1)
                {
                    s[j]--;
                    swap(s[j], s[j - 1]);
                    j--;
                    changed = true;
                }
            }
        }
    }
    cout << s << endl;
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
