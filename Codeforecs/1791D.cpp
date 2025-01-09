#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            vector<ll> p(26,0), su(26,0);
            for(int j=0;j<i;j++)
            {
                p[s[j]-'a']++;
            }
            for(int j=i;j<s.length();j++)
            {
                su[s[j]-'a']++;
            }
        }
        
    }
    return 0;
}