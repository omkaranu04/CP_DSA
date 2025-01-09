#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ll sum = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        sum += s[i] - '0';
    }
    if (sum == 0)
        cout << 0 << endl;
    else if (sum == 1)
        cout << s.length() / 2 << endl;
    else
        cout << (s.length() + 1) / 2 << endl;
    return 0;
}