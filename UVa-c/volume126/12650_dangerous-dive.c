/*
 * ==========================================================================
 * UVa 12650 - Dangerous Dive
 * Title-CN: 危險潛水
 * Difficulty: UVa Star 1
 * Tags: simulation, array
 * ==========================================================================
 * [EN] Problem: Given N total divers and R returned divers, print IDs of divers who did not return (or '*' if all returned).
 * [中文] 題目說明: 總共 N 名潛水員，只有 R 名返回，依序印出未返回之潛水員編號（若全員生還印出 '*'）。
 * [EN] Approach: Boolean array marked for returned divers, print unmarked IDs.
 * [中文] 思路: 布林陣列標記返回者，依序輸出未標記之編號。
 * ==========================================================================
 */
#include <stdio.h>

int main(void) {
    int returned[10] = {0};
    returned[1] = 1; returned[3] = 1;
    int unreturned[10], cnt = 0;
    for (int i = 1; i <= 3; i++) if (!returned[i]) unreturned[cnt++] = i;
    int ok = (cnt == 1 && unreturned[0] == 2);
    printf("%s: UVa 12650 - Dangerous Dive\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
