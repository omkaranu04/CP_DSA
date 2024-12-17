#include <iostream>
#include <vector>
using namespace std;

bool isSubsequence(string s, string t)
{
    int j = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == t[j])
        {
            j++;
        }
        if (j == t.size())
        {
            return true;
        }
    }
    return j == t.size();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;

        int s_len = s.size();
        int t_len = t.size();
        bool possible = false;

        string temp = s;
        int j = 0;
        for (int i = 0; i < s_len; ++i)
        {
            if (temp[i] == '?' || temp[i] == t[j])
            {
                if (temp[i] == '?')
                {
                    temp[i] = t[j];
                }
                if (temp[i] == t[j])
                {
                    j++;
                    if (j == t_len)
                    {
                        possible = true;
                        break;
                    }
                }
            }
        }

        if (possible)
        {
            for (int i = 0; i < s_len; ++i)
            {
                if (temp[i] == '?')
                {
                    temp[i] = 'a';
                }
            }
            cout << "YES" << endl;
            cout << temp << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
