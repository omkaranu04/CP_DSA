#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, a, b;
    cin >> n >> a >> b;
    cout << n - max(n - b, a + 1) + 1 << endl;
    return 0;
}