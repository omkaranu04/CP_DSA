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
        string p = "codeforces";
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != p[i])
                count++;
        }
        cout << count << endl;
    }
    return 0;
}