#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n >= 5)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
    return 0;
}