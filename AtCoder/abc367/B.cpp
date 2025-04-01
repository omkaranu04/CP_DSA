#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    ll n = s.size();
    while (s.back() == '0')
        s.pop_back();
    if (s.back() == '.')
        s.pop_back();
    cout << s << endl;
    return 0;
}