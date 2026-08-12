#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        long long int sum = 0;
        cin >> n;
        while (n >= 1)
        {
            sum += n;
            n /= 2;
        }
        cout << sum << endl;
    }
    return 0;
}