#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int count = 0;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == '|')
        {
            cout << count << " ";
            count = 0;
        }
        else
            count++;
    }
    return 0;
}