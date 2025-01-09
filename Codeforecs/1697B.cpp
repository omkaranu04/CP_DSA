#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    long long int n, q;
    cin >> n >> q;
    long long int prices[n];
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    sort(prices, prices + n);
    reverse(prices, prices + n);
    long long int ps[n + 1];
    ps[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        ps[i] = ps[i - 1] + prices[i - 1];
    }
    while (q--)
    {
        long long int x, y, free;
        cin >> x >> y;
        free = ps[x] - ps[x - y];
        cout << free << endl;
    }

    return 0;
}
