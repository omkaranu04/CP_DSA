#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string p;
    cin>>p;
    ll l;
    cin>>l;
    if(p.length()>=l) cout<<"Yes";
    else cout<<"No";
    return 0;
}