#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << 0 << " " << 0 << " " << endl;
        }
        else
        {
            long long int diff = abs(a - b);
            cout << diff << " " << min(a % diff, diff - a % diff) << " " << endl;
        }
    }
    return 0;
}