#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum += (i * (n - i));
    }
    cout << sum + n << endl;
    return 0;
}