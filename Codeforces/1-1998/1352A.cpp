#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a;
        int mul = 1;
        while (n > 0)
        {
            if (n % 10 != 0)
            {
                a.push_back((n % 10) * mul);
            }
            n /= 10;
            mul *= 10;
        }
        cout << a.size() << endl;
        for (auto i : a)
        {
            cout << i << " ";
        }
    }
    return 0;
}