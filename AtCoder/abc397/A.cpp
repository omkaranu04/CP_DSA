#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    double X;
    cin >> X;
    if (X >= 38.0)
        cout << 1;
    else if (X >= 37.5)
        cout << 2;
    else
        cout << 3;
    return 0;
}