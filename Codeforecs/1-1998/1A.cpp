#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    double n, m, a;
    cin >> n >> m >> a;
    double height = ceil(m / a);
    double width = ceil(n / a);
    long long int answer = (long long int)height * (long long int)width;
    cout << answer << endl;
    return 0;
}