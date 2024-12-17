#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string copy = s;
        sort(copy.begin(), copy.end());
        if (copy == s)
            cout << 1 << endl;
        else
        {
            reverse(copy.begin(), copy.end());
            if (copy == s)
                cout << 2 << endl;
            else
            {
                int count = 0;
                for (int i = 1; i < s.length(); i++)
                {
                    if (s[i] != s[i - 1])
                        count++;
                }
                if (count == 0)
                    cout << 1 << endl;
                else
                    cout << count << endl;
            }
        }
    }
    return 0;
}