#include <bits/stdc++.h>
using namespace std;
bool isfair(long long int n)
{
    long long int num = n;
    bool isFair = true;
    while (n > 0)
    {
        long long int x = n % 10;
        if (x != 0 && num % x != 0)
        {
            isFair = false;
            break;
        }
        n = n / 10;
    }
    return isFair;
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        while (!(isfair(n)))
            n++;
        cout << n << endl;
    }
    return 0;
}