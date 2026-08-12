#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    string s, t;
    cin >> s;
    cin >> t;
    int index = 0;
    while (1)
    {
        int i = size(s) - index - 1;
        int j = size(t) - index - 1;
        if (i >= 0 && j >= 0 && s[i] == t[j])
        {
            index++;
        }
        else
            break;
    }
    cout << size(s) + size(t) - 2 * index << endl;
    return 0;
}