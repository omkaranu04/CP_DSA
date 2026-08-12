#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, x = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "X++")
            x++;
        if (s == "++X")
            ++x;
        if (s == "X--")
            x--;
        if (s == "--X")
            --x;
    }
    cout << x << endl;
    return 0;
}
