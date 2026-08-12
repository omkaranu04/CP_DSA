#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    string p;
    cin >> p;
    int flag = 0;
    for (int i = 0; i < size(p); i++)
    {
        if (p[i] == 'H' || p[i] == 'Q' || p[i] == '9')
        {
            flag = 1;
            cout << "YES" << endl;
            break;
        }
    }
    if (!(flag))
        cout << "NO" << endl;
    return 0;
}