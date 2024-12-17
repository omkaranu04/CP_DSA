#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        if (a == "abc" || a == "bac" || a == "acb" || a == "cba")
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
