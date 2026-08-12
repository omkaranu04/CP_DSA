#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    ll ct = 0;
    while (n != 0)
    {
        if (n % 10 == 4 || n % 10 == 7)
            ct++;
        n /= 10;
    }
    if (ct == 4 || ct == 7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}