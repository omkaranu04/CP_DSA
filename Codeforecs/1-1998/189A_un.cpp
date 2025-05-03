#include <bits/stdc++.h>
using namespace std;
int maximumPieces(int n, int a, int b, int c)
{
    int maxpieces = -1;
    if (n >= a)
    {
        int pieces = 1 + maximumPieces(n - a, a, b, c);
        if (pieces > maxpieces)
        {
            maxpieces = pieces;
        }
    }
    if (n >= b)
    {
        int pieces = 1 + maximumPieces(n - b, a, b, c);
        if (pieces > maxpieces)
        {
            maxpieces = pieces;
        }
    }
    if (n >= c)
    {
        int pieces = 1 + maximumPieces(n - c, a, b, c);
        if (pieces > maxpieces)
        {
            maxpieces = pieces;
        }
    }
    return maxpieces;
}
int main(int argc, char const *argv[])
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << maximumPieces(n, a, b, c) << endl;
    return 0;
}
