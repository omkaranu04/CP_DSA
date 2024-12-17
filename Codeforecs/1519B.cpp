#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k, cost = 0;
        cin >> n >> m >> k;
        int currn = 1, currm = 1;
        if (m != currm)
        {
            cost = cost + currn * (m - currm);
            currm = m;
        }
        if (n != currn)
        {
            cost = cost + currm * (n - currn);
            currn = n;
        }
        if (cost == k)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
