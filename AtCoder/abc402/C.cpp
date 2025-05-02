#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> dish_disliked_count(M + 1, 0);
    vector<vector<int>> ingredient_to_dishes(N + 1);

    for (int i = 1; i <= M; i++)
    {
        int K;
        cin >> K;
        dish_disliked_count[i] = K;

        for (int j = 0; j < K; j++)
        {
            int ingredient;
            cin >> ingredient;
            ingredient_to_dishes[ingredient].push_back(i);
        }
    }

    vector<int> B(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> B[i];
    }

    int can_eat = 0;
    for (int day = 1; day <= N; day++)
    {
        int ingredient = B[day];

        for (int dish : ingredient_to_dishes[ingredient])
        {
            dish_disliked_count[dish]--;
            if (dish_disliked_count[dish] == 0)
            {
                can_eat++;
            }
        }

        cout << can_eat << endl;
    }

    return 0;
}
