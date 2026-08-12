#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long int n, count = 0;
        cin >> n;
        for (int i = 1; i <= 9; i++)
        {
            long long int num = i;
            while (num <= n)
            {
                count++;
                num = num * 10 + i;
            }
        }
        cout << count << endl;
    }

    return 0;
}
