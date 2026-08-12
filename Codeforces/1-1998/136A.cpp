#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        p[a] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << p[i] << " ";
    }
    return 0;
}