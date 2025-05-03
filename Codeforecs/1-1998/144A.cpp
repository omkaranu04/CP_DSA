#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int mina = 1000, minindex;
    int maxa = 0, maxindex;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (a > maxa)
        {
            maxa = a;
            maxindex = i;
        }
        if (a <= mina)
        {
            mina = a;
            minindex = i;
        }
    }
    if (maxindex > minindex)
        cout << (maxindex - 1) + (n - minindex) - 1 << endl;
    else
        cout << (maxindex - 1) + (n - minindex) << endl;
    return 0;
}
