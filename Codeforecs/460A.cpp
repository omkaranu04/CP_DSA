#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    int days = 0;
    int socks = n;
    while (socks > 0)
    {
        days++;
        if (days % m == 0)
            socks++;
        socks--;
    }
    cout << days << endl;
    return 0;
}
