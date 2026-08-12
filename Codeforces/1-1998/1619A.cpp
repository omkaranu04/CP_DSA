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
        if (size(s) % 2 != 0)
            cout << "NO" << endl;
        else
        {
            string s1, s2;
            s1 = s.substr(0, size(s) / 2);
            s2 = s.substr(size(s) / 2, size(s) / 2);
            if (s1 == s2)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
