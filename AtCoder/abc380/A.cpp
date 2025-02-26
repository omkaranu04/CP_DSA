#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string n;
    cin >> n;
    map<char, int> mp;
    for (int i = 0; i < n.size(); i++)
    {
        mp[n[i]]++;
    }
    if (mp['1'] == 1 && mp['2'] == 2 && mp['3'] == 3)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}