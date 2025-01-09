#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int a, b, n;
    cin >> a >> b;
    cin >> n;
    cout << (a * (n - n / 2)) - (b * (n / 2)) << endl;
    return 0;
}
