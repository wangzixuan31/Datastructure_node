#include <stdio.h>

typedef struct {
    double node; // 位置
    
} LocationNode;

void updateTruckLocation(LocationNode* location, double node) {
    location->node = node;
    
}

void printTruckLocation(LocationNode* location) {
    printf("货车当前位置：地点 %.0f", location->node);
}

int main() {
    LocationNode truckLocation;
    LocationNode* truckLocationPtr = &truckLocation;

    // 更新货车位置
    updateTruckLocation(truckLocationPtr, 1);

    // 打印货车位置
    printTruckLocation(truckLocationPtr);

    return 0;
}

