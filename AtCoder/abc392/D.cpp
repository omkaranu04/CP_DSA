#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
    long long int N;
    cin >> N;

    // Store frequency maps for each die
    vector<map<long long int, long long int>> diceFreq(N);
    vector<long int> K(N);

    // Read input and create frequency maps
    for (int i = 0; i < N; i++)
    {
        cin >> K[i];
        for (int j = 0; j < K[i]; j++)
        {
            long long int num;
            cin >> num;
            diceFreq[i][num]++;
        }
    }

    double maxProbability = 0.0;

    // Try each pair of dice
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            long long int matchingOutcomes = 0;

            // For each number on die i
            for (const auto &[num, freq1] : diceFreq[i])
            {
                // If this number also appears on die j
                if (diceFreq[j].count(num))
                {
                    // Add to matching outcomes: freq1 * freq2
                    matchingOutcomes += freq1 * diceFreq[j][num];
                }
            }

            // Calculate probability: (matching outcomes) / (total possible outcomes)
            double probability = (double)matchingOutcomes / (K[i] * K[j]);
            maxProbability = max(maxProbability, probability);
        }
    }

    cout << fixed << setprecision(15) << maxProbability << endl;

    return 0;
}