#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
const ll mod = 1e9 + 7;
const ld PI = atan(1.0) * 4;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a, b, d;
    cin >> a >> b >> d;
    ld rads = d * PI / 180.0;
    ld nx = a * cos(rads) - b * sin(rads);
    ld ny = a * sin(rads) + b * cos(rads);
    cout << setprecision(30) << nx << " " << ny << endl;
    return 0;
}