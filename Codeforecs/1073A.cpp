#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] != s[i - 1])
        {
            cout << "YES" << endl;
            cout << s[i - 1] << s[i] << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}