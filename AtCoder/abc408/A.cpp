#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, S;
    cin >> N >> S;
    vector<int> T(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> T[i];
    }

    int last_tap = 0;
    for (int i = 0; i < N; ++i)
    {
        if (T[i] - last_tap > S)
        {
            cout << "No\n";
            return 0;
        }
        last_tap = T[i];
    }

    cout << "Yes\n";
    return 0;
}
