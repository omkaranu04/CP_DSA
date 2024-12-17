#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
    int years = 0;
    while (a <= b)
    {
        a = 3 * a;
        b = 2 * b;
        years++;
    }
    cout << years;
    return 0;
}