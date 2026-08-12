#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i <= n / 4; i++)
    {
        int rem_sum = n - 4 * i;
        if (rem_sum % 7 == 0)
        {
            int c_4 = i;
            int c_7 = rem_sum / 7;
            while (c_4--)
                cout << "4";
            while (c_7--)
                cout << "7";
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}