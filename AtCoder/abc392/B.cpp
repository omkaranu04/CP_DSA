#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Read input values N and M
    int N, M;
    cin >> N >> M;

    // Create a boolean array to mark present numbers
    vector<bool> present(N + 1, false);

    // Read M numbers and mark them as present
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        present[num] = true;
    }

    // Print missing numbers in ascending order
    cout << N - M << endl;
    bool found = false;
    for (int i = 1; i <= N; i++)
    {
        if (!present[i])
        {
            cout << i << endl;
            found = true;
        }
    }

    // If no missing numbers found
    if (!found)
    {
        for (int i = 1; i <= N; i++)
        {
            if (!present[i])
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}