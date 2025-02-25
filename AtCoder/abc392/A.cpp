#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool checkProduct(vector<int> &arr)
{
    // Check if first two numbers multiply to give the third number
    return (arr[0] * arr[1] == arr[2]);
}

bool solve(vector<int> &A)
{
    // Sort the array to get permutations
    sort(A.begin(), A.end());

    // Try all possible permutations
    do
    {
        if (checkProduct(A))
        {
            return true;
        }
    } while (next_permutation(A.begin(), A.end()));

    return false;
}

int main()
{
    vector<int> A(3);

    // Input
    for (int i = 0; i < 3; i++)
    {
        cin >> A[i];
    }

    // Output
    if (solve(A))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
