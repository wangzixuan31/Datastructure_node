#include <stdio.h>

typedef struct {
    double node; // λ��
    
} LocationNode;

void updateTruckLocation(LocationNode* location, double node) {
    location->node = node;
    
}

void printTruckLocation(LocationNode* location) {
    printf("������ǰλ�ã��ص� %.0f", location->node);
}

int main() {
    LocationNode truckLocation;
    LocationNode* truckLocationPtr = &truckLocation;

    // ���»���λ��
    updateTruckLocation(truckLocationPtr, 1);

    // ��ӡ����λ��
    printTruckLocation(truckLocationPtr);

    return 0;
}

