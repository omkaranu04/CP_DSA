#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

void solve()
{
    ll a,b,m;
    cin>>a>>b>>m;
    a+=1;
    ll sum1=(m*(m-1)/2);
    ll f1=a%m;
    ll f2=(b-a+1)%m;
    ll ans2=(f2)*(f1*2+f2-1)/2;
    if(f1+f2>=m+1){ans2=(f1+m-1)*(m-f1)/2 + (f2+f1-m)*(f2+f1-m-1)/2;}
    ll ans=((b-a+1)/m)*sum1+ans2;
    // cout<<((b-a+1)/m)*sum1<<" "<<(f2)*(f1*2+f2-1)/2<<" "<<endl;
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