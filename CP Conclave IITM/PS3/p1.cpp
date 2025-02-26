#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    for (int i = 0; i < size(s1); i++)
    {
        s1[i] = tolower(s1[i]);
    }
    for (int i = 0; i < size(s2); i++)
    {
        s2[i] = tolower(s2[i]);
    }

    if (s1 < s2)
        cout << -1;
    if (s1 > s2)
        cout << 1;
    if (s1 == s2)
        cout << 0;
    return 0;
}
