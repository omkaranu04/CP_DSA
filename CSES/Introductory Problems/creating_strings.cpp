#include <bits/stdc++.h>
using namespace std;
#define ll long long int
string s;
vector<bool> taken;
set<string> ans;
// void solve(string &temp)
// {
//     if (temp.size() == s.size())
//     {
//         ans.insert(temp);
//         return;
//     }
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (!taken[i])
//         {
//             taken[i] = true;
//             temp.push_back(s[i]);
//             solve(temp);
//             temp.pop_back();
//             taken[i] = false;
//         }
//     }
// }
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    sort(s.begin(), s.end());
    taken.resize(s.size() + 1, false);
    string temp = "";
    // solve(temp);
    ans.insert(s);
    while (next_permutation(s.begin(), s.end()))
        ans.insert(s);
    cout << ans.size() << endl;
    for (auto &i : ans)
        cout << i << endl;
    return 0;
}