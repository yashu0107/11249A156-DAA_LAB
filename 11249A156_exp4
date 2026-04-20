#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

struct Item {
    int profit;
    int weight;
    float ratio;
};

int main() {
    int n, capacity;
    float totalProfit = 0;

    printf("Enter number of items: ");
    if (scanf("%d", &n) != 1) return 1;

    // Use malloc to allocate memory dynamically
    struct Item *item = (struct Item *)malloc(n * sizeof(struct Item));
    
    if (item == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter profit and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &item[i].profit, &item[i].weight);
        item[i].ratio = (float)item[i].profit / item[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Simple Bubble Sort by Ratio (Descending)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (item[i].ratio < item[j].ratio) {
                struct Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    

    printf("\nItems selected:\n");
    for (int i = 0; i < n; i++) {
        if (capacity == 0) break; // Optimization: stop if bag is full

        if (capacity >= item[i].weight) {
            // Take full item
            printf("Item (P:%d, W:%d) taken fully\n", item[i].profit, item[i].weight);
            totalProfit += item[i].profit;
            capacity -= item[i].weight;
        } else {
            // Take fraction of item
            float fraction = (float)capacity / item[i].weight;
            printf("Item (P:%d, W:%d) taken partially (%.2f%%)\n", 
                    item[i].profit, item[i].weight, fraction * 100);
            totalProfit += item[i].profit * fraction;
            capacity = 0; // Bag is now full
            break;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    // Clean up memory
    free(item);
    return 0;
}
 
