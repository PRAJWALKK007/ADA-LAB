#include <stdio.h>


int max(int a, int b) {
    return (a > b) ? a : b;
}


void knapsack(int n, int capacity, int weights[], int profits[]) {
    int dp[n+1][capacity+1];
    int i, w;


    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i-1] <= w)
                dp[i][w] = max(profits[i-1] + dp[i-1][w - weights[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }


    int max_profit = dp[n][capacity];
    printf("Maximum Profit: %d\n", max_profit);


    printf("Objects selected:\n");
    w = capacity;
    for (i = n; i > 0 && max_profit > 0; i--) {
        if (max_profit == dp[i-1][w])
            continue;
        else {

            printf("Object %d (Weight = %d, Profit = %d)\n", i, weights[i-1], profits[i-1]);
            max_profit -= profits[i-1];
            w -= weights[i-1];
        }
    }
}

int main() {
    int n;
    printf("Enter number of objects: ");
    scanf("%d", &n);

    int weights[n];
    int profits[n];


    printf("Enter weights of the objects:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter profits of the objects:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &profits[i]);
    }

    int capacity; // Capacity of the knapsack
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Display the weights and profits
    printf("\nObjects:\n");
    printf("Weight\tProfit\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", weights[i], profits[i]);
    }

    printf("\nKnapsack Capacity: %d\n", capacity);

    // Solve knapsack problem
    knapsack(n, capacity, weights, profits);

    return 0;
}
