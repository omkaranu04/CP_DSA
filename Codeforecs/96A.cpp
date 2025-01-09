#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int l0 = s.find("0000000");
    int l1 = s.find("1111111");
    if (l0 >= 0 || l1 >= 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}