#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll A, B;
    cin >> A >> B;
    if ((A + B) % 2 == 0 && A != B)
        cout << 3 << endl;
    else if (A == B)
        cout << 1 << endl;
    else
        cout << 2 << endl;
    return 0;
}