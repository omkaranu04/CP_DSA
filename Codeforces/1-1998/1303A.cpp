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
        int first_1 = 0;
        int last_1 = s.length() - 1;
        while (s[first_1] == '0')
        {
            first_1++;
        }
        while (s[last_1] == '0')
        {
            last_1--;
        }
        int count = 0;
        for (int i = first_1; i <= last_1; i++)
        {
            if (s[i] == '0')
                count++;
        }
        cout << count << endl;
    }
    return 0;
}