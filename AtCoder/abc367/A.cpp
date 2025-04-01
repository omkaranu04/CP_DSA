#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll A, B, C;
    cin >> A >> B >> C;
    if (B < C)
    {
        if (B < A && A < C)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    else
    {
        if (C < A && A < B)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}