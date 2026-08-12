#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> a(7);
    for (int i = 0; i < 7; i++)
    {
        cin >> a[i];
    }
    int i = 0;
    while (1)
    {
        n -= a[i];
        if (n <= 0)
            break;
        i++;
        i = i % 7;
    }
    cout << i + 1 << endl;
    return 0;
}