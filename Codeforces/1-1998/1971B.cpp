#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        string ans = s;
        sort(s.begin(), s.end());

        if (s == string(s.rbegin(), s.rend()) || s[0] == s[s.size() - 1])
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            if (ans == s)
            {
                reverse(s.begin(), s.end());
                cout << s << endl;
            }
            else
                cout << s << endl;
        }
    }

    return 0;
}
