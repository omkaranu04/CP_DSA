#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<char> output;
        char c = s[0];
        for (int i = 1; i < n; i++)
        {
            if (s[i] == c)
            {
                output.push_back(c);
                c = s[i + 1];
                i++;
            }
        }
        for (auto element : output)
        {
            cout << element;
        }
        cout << endl;
    }
    return 0;
}