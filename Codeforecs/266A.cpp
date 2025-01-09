#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int r = 0, g = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R')
        {
            if (s[i] == 'R' && s[i + 1] == 'R')
            {
                r++;
            }
        }
        if (s[i] == 'G')
        {
            if (s[i] == 'G' && s[i + 1] == 'G')
            {
                g++;
            }
        }
        if (s[i] == 'B')
        {
            if (s[i] == 'B' && s[i + 1] == 'B')
            {
                b++;
            }
        }
    }
    cout << r + g + b << endl;
    return 0;
}