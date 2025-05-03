#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int k, r;
    cin >> k >> r;
    int count = 1;
    while ((k * count) % 10 != 0 && (k * count) % 10 != r)
    {
        count++;
    }
    cout << count << endl;
    return 0;
}