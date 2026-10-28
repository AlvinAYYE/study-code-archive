/*
 * Title-CN: 設計停車系統
 * LeetCode 1603. Design Parking System
 *
 * 題意完整翻譯：
 *   設計停車系統，分別有 big、medium、small 三種固定數量的車位。呼叫 addCar(carType) 時，若該車種還有空位就佔用一格並回傳
 *   true；若沒有空位則回傳 false。carType 1、2、3 分別代表大、中、小型車。
 *
 * 範例：
 *   1. 建立 ParkingSystem(1,1,0) 後，依序加入大車、中車、小車、大車，結果是 true、true、false、false。
 *
 * 限制：
 *   - big、medium、small 各介於 0 到 1000
 *   - carType 為 1、2 或 3
 *   - addCar 最多呼叫 1000 次
 *
 * 解題步驟：
 *   1. 建立物件時，把三種車位剩餘數量分別存起來。
 *   2. addCar 根據 carType 找到相對應的數量。
 *   3. 若數量為 0，回傳 false；否則數量減 1 並回傳 true。
 *
 * 複雜度：
 *   時間：每次 addCar 為 O(1)。
 *   空間：O(1)，只保存三種車位數量。
 *
 * LeetCode C API：
 *   ParkingSystem* parkingSystemCreate(int big, int medium, int small); bool
 *   parkingSystemAddCar(ParkingSystem* obj, int carType); void
 *   parkingSystemFree(ParkingSystem* obj);
 */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int remaining[4];
} ParkingSystem;

ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem* obj = (ParkingSystem*)malloc(sizeof(ParkingSystem));
    obj->remaining[1] = big;
    obj->remaining[2] = medium;
    obj->remaining[3] = small;
    return obj;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
    if (obj->remaining[carType] == 0) {
        return false;
    }
    --obj->remaining[carType];
    return true;
}

void parkingSystemFree(ParkingSystem* obj) {
    free(obj);
}

int main(void) {
    ParkingSystem* parking = parkingSystemCreate(1, 1, 0);
    assert(parkingSystemAddCar(parking, 1));
    assert(parkingSystemAddCar(parking, 2));
    assert(!parkingSystemAddCar(parking, 3));
    assert(!parkingSystemAddCar(parking, 1));
    parkingSystemFree(parking);
    puts("PASS 1603 ParkingSystem");
    return 0;
}
