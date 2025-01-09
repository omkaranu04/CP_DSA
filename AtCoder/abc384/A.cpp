#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    char c1, c2;
    cin >> n >> c1 >> c2;
    string s;
    cin >> s;
    for (auto &i : s)
    {
        if (i != c1)
            i = c2;
    }
    cout << s << endl;
    return 0;
}