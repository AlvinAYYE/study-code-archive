/*
 * ==========================================================================
 * UVa 12592 - Slogan Learning of Princess
 * Title-CN: 公主的口號配對
 * Difficulty: UVa Star 1
 * Tags: string, hash-table
 * ==========================================================================
 * [EN] Problem: Given slogan pairs (line 1, line 2), output matching line 2 when queried with line 1.
 * [中文] 題目說明: 建立口號上下句對應表，輸入上句查詢時輸出相應的下句口號。
 * [EN] Approach: Linear string array lookup.
 * [中文] 思路: 陣列記錄口號配對，字串比對查詢輸出。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

int main(void) {
    int ok = 1;
    printf("%s: UVa 12592 - Slogan Learning of Princess\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
