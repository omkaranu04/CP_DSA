#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    vector<int> a(3);
    a[0] = x1;
    a[1] = x2;
    a[2] = x3;
    sort(a.begin(), a.end());
    cout << abs(a[1] - a[0]) + abs(a[1] - a[2]) << endl;
    return 0;
}