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
    if (s == "N")
        cout << "S";
    else if (s == "S")
        cout << "N";
    else if (s == "W")
        cout << "E";
    else if (s == "E")
        cout << "W";
    else if (s == "SW")
        cout << "NE";
    else if (s == "SE")
        cout << "NW";
    else if (s == "NW")
        cout << "SE";
    else if (s == "NE")
        cout << "SW";
    return 0;
}