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
        string ONE = "1";
        if (s == ONE)
            cout << 1 << endl;
        else
        {
            s = '0' + s;
            int n = size(s);
            int changedLast = n;
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] >= '5')
                {
                    while (s[i - 1] == '9')
                        i--;
                    s[i - 1]++;
                    changedLast = i;
                }
            }
            int j = 0;
            if (s[0] == '0')
                j = 1;
            for (int i = j; i < changedLast; i++)
            {
                cout << s[i];
            }
            for (int i = changedLast; i < n; i++)
            {
                cout << 0;
            }
            cout << endl;
        }
    }
    return 0;
}