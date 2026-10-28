/*
 * LeetCode 2591. Distribute Money to Maximum Children
 * Title-CN: 分配金錢給最多兒童
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/distribute-money-to-maximum-children/
 *
 * [中文] 題目說明
 *     將 money 元分給 children 個孩子，必須把錢全部分完，每人至少 1 元，
 *     而且不能有人恰好拿到 4 元。請回傳最多有幾人能恰好拿到 8 元；若無法
 *     符合規則，回傳 -1。
 *
 * [中文] 範例
 *     1. money = 20、children = 3，輸出 1；例如分成 8、9、3 元。
 *     2. money = 16、children = 2，輸出 2；兩人各拿 8 元。
 *
 * [中文] 限制
 *     - 1 <= money <= 200。
 *     - 2 <= children <= 30。
 *
 * [中文] 解題步驟
 *     1. 先給每個孩子 1 元。若總錢少於孩子數，無法分配，回傳 -1。
 *     2. 剩下的每 7 元可讓一個孩子從 1 元補到 8 元，因此先取
 *        min((money - children) / 7, children) 個 8 元孩子。
 *     3. 若每個孩子都拿 8 元但仍有剩錢，就必須減少一個 8 元名額，才能把
 *        剩餘金額交給某人。若只剩一位非 8 元孩子且他會拿到 4 元，也要再
 *        減少一個名額以避開非法分配。時間 O(1)，額外空間 O(1)。
 *
 * LeetCode C 函式簽名：int distMoney(int money, int children)
 */
#include <stdio.h>

int distMoney(int money, int children) {
    int extra, eights;
    if (money < children) return -1;
    extra = money - children;
    eights = extra / 7;
    if (eights > children) eights = children;
    if (eights == children && extra % 7 != 0) --eights;
    else if (eights == children - 1 && extra % 7 == 3) --eights;
    return eights;
}

int main(void) {
    int ok = 1;
    ok = ok && distMoney(20, 3) == 1;
    ok = ok && distMoney(16, 2) == 2;
    ok = ok && distMoney(2, 3) == -1;
    ok = ok && distMoney(3, 2) == 0;
    ok = ok && distMoney(12, 2) == 0;
    ok = ok && distMoney(24, 3) == 3;
    printf("%s: 2591 distribute-money-to-maximum-children\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
