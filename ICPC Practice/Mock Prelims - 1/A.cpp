#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

void solve()
{
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0 ; i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    int j=0;
    ll ans=0;
    while (j<n-1){
        if(a[j+1]==a[j] || a[j+1]==a[j]+1){ans+=1;j+=2;continue;}
        j+=1;
    }
    cout<<ans<<endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}