#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        char a[64];
        string s[64];
        int j = 0;
        for (int i = 0; i < 64; i++)
        {
            cin >> a[i];
            if (!(a[i] == '.'))
            {
                s[j] = a[i];
                j++;
            }
        }
        for (int i = 0; i < j; i++)
        {
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}