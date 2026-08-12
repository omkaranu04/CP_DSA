#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int a, b, d, m;
    cin >> a >> b;
    int h = a;
    while (a >= b)
    {
        d = a / b;
        h += d;
        m = a % b;
        a = d + m;
    }
    cout << h << endl;
    return 0;
}