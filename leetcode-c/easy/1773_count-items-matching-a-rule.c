/*
 * LeetCode 1773. Count Items Matching a Rule
 * Title-CN: 符合規則的項目數量
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/count-items-matching-a-rule/
 *
 * [中文] 題目說明
 *     每個 items[i] 都有三個欄位 [type, color, name]，代表物品的類型、
 *     顏色和名稱。另給定 ruleKey 與 ruleValue；若物品對應欄位的值等於
 *     ruleValue，該物品就符合規則。type、color、name 分別是第 0、1、2 欄。
 *     請回傳符合規則的物品數量。
 *
 * [中文] 範例
 *     1. items = [[phone,blue,pixel],[computer,silver,lenovo],[phone,gold,iphone]]，
 *        ruleKey = color、ruleValue = silver，輸出 1。
 *     2. items = [[phone,blue,pixel],[computer,silver,phone],[phone,gold,iphone]]，
 *        ruleKey = type、ruleValue = phone，輸出 2。
 *
 * [中文] 限制
 *     - 1 <= items.length <= 10^4；每個欄位及 ruleValue 長度為 1 到 10。
 *     - ruleKey 一定是 type、color 或 name；字串只含小寫英文字母。
 *
 * [中文] 解題步驟
 *     1. 將 ruleKey 對應成欄位索引：type 是 0、color 是 1、name 是 2。
 *     2. 逐項比較該欄位字串和 ruleValue；相同就把計數加一。
 *     3. 回傳計數。每次比較最多檢查 10 個字元，時間 O(n)，額外空間 O(1)。
 *
 * LeetCode C 函式簽名：
 *     int countMatches(char*** items, int itemsSize, int* itemsColSize,
 *                      char* ruleKey, char* ruleValue)
 */
#include <stdio.h>
#include <string.h>

int countMatches(char ***items, int itemsSize, int *itemsColSize, char *ruleKey, char *ruleValue) {
    int column = strcmp(ruleKey, "type") == 0 ? 0 :
                 (strcmp(ruleKey, "color") == 0 ? 1 : 2);
    int count = 0, i;
    (void)itemsColSize;
    for (i = 0; i < itemsSize; ++i) {
        if (strcmp(items[i][column], ruleValue) == 0) ++count;
    }
    return count;
}

int main(void) {
    int ok = 1;
    char *a0[] = {"phone", "blue", "pixel"};
    char *a1[] = {"computer", "silver", "lenovo"};
    char *a2[] = {"phone", "gold", "iphone"};
    char **items1[] = {a0, a1, a2};
    int cols1[] = {3, 3, 3};
    char *b1[] = {"computer", "silver", "phone"};
    char **items2[] = {a0, b1, a2};
    int cols2[] = {3, 3, 3};
    ok = ok && countMatches(items1, 3, cols1, "color", "silver") == 1;
    ok = ok && countMatches(items2, 3, cols2, "type", "phone") == 2;
    printf("%s: 1773 count-items-matching-a-rule\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
