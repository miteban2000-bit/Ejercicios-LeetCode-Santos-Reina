#include <stdio.h>

int maxProfit(int* prices, int size) {
    int min_price = 1000000;  // Un número grande para empezar
    int max_profit = 0;

    for (int i = 0; i < size; i++) {
        if (prices[i] < min_price) {
            min_price = prices[i];
        } else {
            int profit = prices[i] - min_price;
            if (profit > max_profit) {
                max_profit = profit;
            }
        }
    }
    return max_profit;
}

int main() {
    int prices1[] = {7, 1, 5, 3, 6, 4};
    int size1 = sizeof(prices1) / sizeof(prices1[0]);

    int prices2[] = {7, 6, 4, 3, 1};
    int size2 = sizeof(prices2) / sizeof(prices2[0]);

    printf("Máxima ganancia (Ejemplo 1): %d\n", maxProfit(prices1, size1));
    printf("Máxima ganancia (Ejemplo 2): %d\n", maxProfit(prices2, size2));

    return 0;
}