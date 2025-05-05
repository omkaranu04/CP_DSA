#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    vector<bool> seen(26, false);
    for(auto c:s) seen[c-'a'] = true;
    for(int i=0;i<26;i++)
    {
        if(!seen[i])
        {
            cout<<char(i+'a')<<endl;
            return 0;
        }
    }
    return 0;
}