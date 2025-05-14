#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
int main()
{
    ll n;
    cin>>n;
    vector<pair<ll,ll>> inters(n);
    for(ll i=0;i<n;i++) cin>>inters[i].first>>inters[i].second;
    sort(inters.begin(), inters.end());
    vector<pair<ll,ll>> ans;
    for(auto x:inters)
    {
        auto &it = ans.back();
        if(ans.empty() || x.first > it.second) ans.push_back(x);
        else it.second = max(it.second, x.second);
    }
    ll xans = 0;
    for(auto x:ans) xans += (x.second - x.first + 1);
    cout<<xans<<endl;
    return 0;
}