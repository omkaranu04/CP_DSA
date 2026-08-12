#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, n;
        cin >> a >> b >> n;
        int step = 0;
        ll sum = 0;
        while (sum <= n)
        {
            if (a > b)
            {
                b += a;
                sum = b;
                step++;
            }
            else
            {
                a += b;
                sum = a;
                step++;
            }
            if (sum > n)
                break;
        }
        cout << step << endl;
    }
    return 0;
}