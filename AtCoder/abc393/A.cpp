#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == "sick" && s2 == "fine")
        cout << 2 << endl;
    if (s1 == "sick" && s2 == "sick")
        cout << 1 << endl;
    if (s1 == "fine" && s2 == "fine")
        cout << 4 << endl;
    if (s1 == "fine" && s2 == "sick")
        cout << 3 << endl;
    return 0;
}