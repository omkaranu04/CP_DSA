#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> c(n);
        int cntr = 0, cntb = 0, blank = 0;
        for(int i=0;i<n;i++)
        {
            cin>>c[i];
            if(c[i]==1) cntr++;
            else if(c[i]==2) cntb++;
            else blank++;
        }
        int diff = abs(cntr - cntb);
        if(blank < diff || (blank - diff) % 2 != 0) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}
