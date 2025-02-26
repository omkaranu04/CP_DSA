#include <stdio.h>

typedef struct {
    int latest_time;
    int cost;
    int index;
} Sweet;

// Function to swap two Sweet structs
void swap(Sweet *a, Sweet *b) {
    Sweet temp = *a;
    *a = *b;
    *b = temp;
}

// Greedy algorithm to select sweets and minimize cost
void selectSweets(Sweet sweets[], int n) {
    // Sort the sweets based on their latest times using Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sweets[j].latest_time > sweets[j + 1].latest_time) {
                swap(&sweets[j], &sweets[j + 1]);
            }
        }
    }
    
    int current_time = 0;
    int total_cost = 0;

    printf("Optimally selected sweet varieties: ");

    for (int i = 0; i < n; i++) {
        if (sweets[i].latest_time >= current_time + 1) {
            printf("%d ", sweets[i].index);
            total_cost += sweets[i].cost;
            current_time++;
        }
    }

    printf("\nTotal cost: %d\n", total_cost);
}

int main() {
    int n = 10; // Number of sweet varieties
    Sweet sweets[] = {
        {9, 150, 1}, {2, 20, 2}, {5, 180, 3}, {7, 10, 4}, {4, 250, 5},
        {2, 200, 6}, {5, 80, 7}, {7, 100, 8}, {4, 120, 9}, {3, 50, 10}
    };

    selectSweets(sweets, n);

    return 0;
}
