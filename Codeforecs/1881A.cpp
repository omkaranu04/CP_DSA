#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        string x,s;
        cin>>x;
        cin>>s;
        int count = 0;
        while(x.length()<s.length())
        {
            x += x;
            count++;
        }
    }
    return 0;
}