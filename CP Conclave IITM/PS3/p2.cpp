#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (size(s) <= 10)
        {
            cout << s << endl;
        }
        else
        {
            cout << s[0] << size(s) - 2 << s[size(s) - 1] << endl;
        }
    }
    return 0;
}
