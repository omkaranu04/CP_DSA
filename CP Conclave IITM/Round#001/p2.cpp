#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    long long int a, b;
    cin >> a >> b;
    cout << (a * b) / __gcd(a, b) << endl;
    return 0;
}
