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
    stack<char> ss;
    unordered_map<char, char> matching = {{')', '('}, {']', '['}, {'>', '<'}};
    for (auto x : s)
    {
        if (x == '(' || x == '<' || x == '[')
            ss.push(x);
        else
        {
            if (ss.empty() || ss.top() != matching[x])
            {
                cout << "No" << endl;
                return 0;
            }
            ss.pop();
        }
    }
    if (ss.empty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}