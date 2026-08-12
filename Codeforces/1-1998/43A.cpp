#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int count1 = 1, count2 = 0;
    string s2;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[0])
            count1++;
        else
        {
            s2 = s[i];
            count2++;
        }
    }
    if (count1 > count2)
        cout << s[0] << endl;
    else
        cout << s2 << endl;
    return 0;
}