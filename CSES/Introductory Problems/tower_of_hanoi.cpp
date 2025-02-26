#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// from a to c using b
void solve(int n, int a, int b, int c)
{
    if (n == 0)
        return;
    solve(n - 1, a, c, b);
    cout << a << " " << c << endl;
    solve(n - 1, b, a, c);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cout << (1 << n) - 1 << endl;
    solve(n, 1, 2, 3);
    return 0;
}