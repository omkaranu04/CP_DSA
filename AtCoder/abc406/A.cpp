#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int deadline_minutes = A * 60 + B;
    int submission_minutes = C * 60 + D;

    if (submission_minutes < deadline_minutes) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
