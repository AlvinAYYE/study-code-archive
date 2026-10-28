/*
 * Title-CN: 水壺問題
 * LeetCode 365. Water and Jug Problem
 *
 * 題目翻譯：有容量分別為 x、y 的兩個水壺，水源無限。可以把水壺裝滿、倒空，
 * 或把一壺水倒進另一壺直到前者倒空或後者裝滿。判斷能否量出剛好 target 的水。
 *
 * 例子：x=3、y=5、target=4 時可以：先裝滿 5 公升壺，倒進 3 公升壺，
 * 再把 3 公升壺倒空，將剩下的 2 公升倒入 3 公升壺；重複後可量出 4 公升。
 *
 * 限制：壺的容量與目標量都不超過 1000。
 *
 * 解題步驟：每次操作只會讓水量增加或減少 x 或 y，因此可量出的水量都是
 * gcd(x,y) 的倍數。裴蜀定理也保證，0 到 x+y 之間每個這樣的倍數都能由操作量出。
 * 所以只需確認 target 不超過總容量，且能被兩個容量的最大公因數整除。
 *
 * 複雜度：輾轉相除法時間 O(log(min(x,y)))，額外空間 O(1)。
 *
 * LeetCode 提交區：保留 canMeasureWater 函式；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdbool.h>

static int greatestCommonDivisor(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

bool canMeasureWater(int x, int y, int target) {
    if (target == 0) {
        return true;
    }
    if (target > x + y) {
        return false;
    }
    return target % greatestCommonDivisor(x, y) == 0;
}

int main(void) {
    assert(canMeasureWater(3, 5, 4));
    assert(!canMeasureWater(2, 6, 5));
    assert(canMeasureWater(1, 2, 3));
    assert(canMeasureWater(3, 5, 0));
    assert(!canMeasureWater(3, 5, 9));
    return 0;
}
