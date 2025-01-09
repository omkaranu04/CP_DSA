#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    long long int n;
    cin >> n;
    long long int arr[n];
    for (int i = 0; i < n; i++)
    {
        long long int a, b, count = 0;
        cin >> a >> b;
        if (a % b == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            int rem = a % b;
            cout << (b - rem) << endl;
        }
    }
    return 0;
}
