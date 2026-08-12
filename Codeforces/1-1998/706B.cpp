#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int x[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    int q;
    cin >> q;
    int m[q];
    for (int i = 0; i < q; i++)
    {
        cin >> m[i];
    }
    sort(x, x + n);
    for (int i = 0; i < q; i++)
    {
        int count = upper_bound(x, x + n, m[i]) - x;
        cout << count << endl;
    }
    return 0;
}
