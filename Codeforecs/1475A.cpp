#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        if (n & (n - 1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}