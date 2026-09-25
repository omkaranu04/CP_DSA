#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    if (s[s.length() - 1] == 'e')
        cout << s << 'r' << endl;
    else
        cout << s << "er" << endl;
    return 0;
}