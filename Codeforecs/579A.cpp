#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    long long int count = 0;
    while (n > 0)
    {
        if (n % 2 == 1)
            count++;
        n = n / 2;
    }
    cout << count << endl;
    return 0;
}