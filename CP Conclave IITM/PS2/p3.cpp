#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    long long int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long int n;
        cin >> n;
        long long int a, b, count = 0;
        a = n - 1;
        b = 1;
        while (a > b)
        {
            count++;
            a--;
            b++;
        }
        cout << count << endl;
    }
    return 0;
}
