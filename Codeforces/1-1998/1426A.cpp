#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int floor = 1;
        if (n == 1 || n == 2)
        {
            cout << 1 << endl;
        }
        else
        {
            n -= 2;
            while (n > 0)
            {
                n -= x;
                floor++;
            }
            cout << floor << endl;
        }
    }
    return 0;
}