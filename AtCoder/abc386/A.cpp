#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<int, int> mp;
    for (int i = 0; i < 4; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    for (auto i : mp)
    {
        if (i.second == 3)
        {
            cout << "Yes\n";
            return 0;
        }
        if (i.second == 2)
        {
            for (auto j : mp)
            {
                if (j.first != i.first)
                {
                    if (j.second == 2)
                    {
                        cout << "Yes\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No\n";
    return 0;
}