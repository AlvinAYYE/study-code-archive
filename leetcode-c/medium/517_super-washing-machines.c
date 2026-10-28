/*
 * LeetCode 517. Super Washing Machines（超級洗衣機）
 *
 * 題意（繁體中文）：
 *   n 台洗衣機排成一列，machines[i] 是第 i 台目前的衣服數。每一步可以
 *   同時選擇任意台洗衣機，每台各把一件衣服送到左右相鄰的一台。請回傳讓
 *   每台洗衣機衣服數相同所需的最少步數；若總衣服無法平均分配，回傳 -1。
 *
 * 範例：
 *   1. machines=[1,0,5]，回傳 3。每台最後有 2 件；最右側的多餘衣服須逐步
 *      往左傳，最終三台都變成 2 件。
 *   2. machines=[0,3,0]，回傳 2。中間洗衣機可在兩步內分別把衣服送往兩側。
 *   3. machines=[0,2,0]，回傳 -1，因為 2 件衣服不能平均分給 3 台。
 *
 * 限制：1 <= n <= 10^4；0 <= machines[i] <= 10^5。
 *
 * 解題步驟：
 *   1. 先加總衣服數。若總數不能被 n 整除，就不可能讓每台數量相同。
 *   2. 設平均數為 avg。從左到右計算每台的差額 diff=machines[i]-avg。
 *      累積差額 balance 代表目前位置左側必須跨過邊界流動的衣服淨數。
 *   3. 每一步一條相鄰邊最多傳一件，因此 |balance| 是必要步數下界；若單台
 *      多出 diff 件，它每一步最多送一件，diff 也是下界。答案取兩種下界的
 *      最大值。
 *
 * 複雜度：時間 O(n)，額外空間 O(1)。總和與流量使用 long long 避免溢位。
 * LeetCode C API：int findMinMoves(int* machines, int machinesSize)
 */
#include <stdio.h>

int findMinMoves(int *machines, int machinesSize) {
    long long total = 0;
    for (int i = 0; i < machinesSize; ++i) total += machines[i];
    if (total % machinesSize != 0) return -1;

    long long average = total / machinesSize;
    long long balance = 0;
    long long answer = 0;

    for (int i = 0; i < machinesSize; ++i) {
        long long difference = (long long)machines[i] - average;
        balance += difference;

        long long boundaryMoves = balance < 0 ? -balance : balance;
        if (boundaryMoves > answer) answer = boundaryMoves;
        if (difference > answer) answer = difference;
    }
    return (int)answer;
}

int main(void) {
    int machines1[] = {1, 0, 5};
    int machines2[] = {0, 3, 0};
    int machines3[] = {0, 2, 0};
    int machines4[] = {0, 0, 0, 4};
    int passed = findMinMoves(machines1, 3) == 3 &&
                 findMinMoves(machines2, 3) == 2 &&
                 findMinMoves(machines3, 3) == -1 &&
                 findMinMoves(machines4, 4) == 3;
    puts(passed ? "PASS: 517 super-washing-machines"
                : "FAIL: 517 super-washing-machines");
    return passed ? 0 : 1;
}
