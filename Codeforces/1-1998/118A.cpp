#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    vector<char> output;
    for (int i = 0; i < size(s); i++)
    {
        if (!(s[i] == 'A' || s[i] == 'O' || s[i] == 'Y' || s[i] == 'E' || s[i] == 'U' || s[i] == 'I' || s[i] == 'a' || s[i] == 'o' || s[i] == 'y' || s[i] == 'e' || s[i] == 'u' || s[i] == 'i'))
        {
            output.push_back('.');
            output.push_back(tolower(s[i]));
        }
    }
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i];
    }

    return 0;
}