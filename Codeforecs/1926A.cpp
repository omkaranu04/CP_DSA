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
        int counta = 0, countb = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'A')
                counta++;
            else
                countb++;
        }
        cout << (counta > countb ? 'A' : 'B') << endl;
    }
    return 0;
}