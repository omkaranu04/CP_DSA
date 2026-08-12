#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, count[26] = {0};
    cin >> n;
    string s;
    cin >> s;
    if (n == 1)
    {
        cout << "Yes" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[s[i] - 'a']++;
    }
    bool recolour = false;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 1)
        {
            recolour = true;
            break;
        }
    }
    if (recolour)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
