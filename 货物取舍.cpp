#include <stdio.h>

// 定义物品的结构体
typedef struct {
    int weight;
    int value;
} Item;

// 按照物品总价值与物品量之比进行排序
void sortByRatio(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double ratio1 = (double)items[j].value / items[j].weight;
            double ratio2 = (double)items[j + 1].value / items[j + 1].weight;
            if (ratio1 < ratio2) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

// 动态规划解决部分背包问题
int knapsack(Item items[], int n, int capacity) {
    int dp[capacity + 1];

    for (int i = 0; i <= capacity; i++) {
        dp[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = capacity; j >= items[i].weight; j--) {
            int remainingCapacity = j - items[i].weight;
            int totalValue = items[i].value + dp[remainingCapacity];
            if (totalValue > dp[j]) {
                dp[j] = totalValue;
            }
        }
    }

    return dp[capacity];
}

int main() {
    // 定义物品数组
    Item items[] = {
        {5, 50},
        {25, 200},
        {30, 180},
        {45, 225},
        {50, 200}
    };

    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 100;

    // 按照物品总价值与物品量之比进行排序
    sortByRatio(items, n);

    int maxValue = knapsack(items, n, capacity);
    printf("背包中物品的最大价值为: %d\n", maxValue);

    return 0;
}

