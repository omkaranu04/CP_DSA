#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll count = 0;
        ll answer = 0;
        for (auto c : s)
        {
            if (c == '1')
                count++;
            else if (c == '0' && count)
                answer += (count + 1);
        }
        cout << answer << endl;
    }
    return 0;
}