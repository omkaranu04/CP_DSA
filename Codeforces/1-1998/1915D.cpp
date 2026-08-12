#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans;
        while (!s.empty())
        {
            int count = 0;
            if (s.back() == 'a' || s.back() == 'e')
                count = 2;
            else
                count = 3;
            while (count--)
            {
                ans += s.back();
                s.pop_back();
            }
            ans += '.';
        }
        ans.pop_back();
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}