#include <bits/stdc++.h>
using namespace std;
#define ll double
int main(int argc, char const *argv[])
{
    ll h, l;
    cin >> h >> l;
    ll answer = (l * l - h * h) / (2.0 * h);
    cout << setprecision(10) << answer << endl;
    return 0;
}