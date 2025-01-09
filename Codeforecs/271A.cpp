#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int y;
    cin >> y;
    while (1)
    {
        y = y + 1;
        int a = y % 10;
        int b = (y / 10) % 10;
        int c = (y / 100) % 10;
        int d = y / 1000;
        if (a != b && a != c && a != d && b != d && b != c && c != d)
        {
            break;
        }
    }
    cout << y << endl;
    return 0;
}
