#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int x;
    cin >> x;
    int steps = 0;
    for (int i = 5; i >= 1; i--)
    {
        steps = steps + (x / i);
        x = x % i;
    }
    cout << steps << endl;
    return 0;
}