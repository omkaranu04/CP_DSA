#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, m;
        cin >> n >> m;
        long long int cost = 0, currposi = 1, currposj = 1;
        while (currposj < m)
        {
            cost += (currposi - 1) * m + currposj;
            currposj++;
        }
        while (currposi < n)
        {
            cost += (currposi - 1) * m + currposj;
            currposi++;
        }
        cost += ((n - 1) * m) + m;
        cout << cost << endl;
    }
    return 0;
}