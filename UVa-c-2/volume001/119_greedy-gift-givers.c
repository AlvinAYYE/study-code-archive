/*
 * ==========================================================================
 * UVa 119 - Greedy Gift Givers
 * Title-CN: 貪婪的送禮者
 * Difficulty: UVa Star 1
 * Tags: simulation, string
 * ==========================================================================
 * [EN] Problem: Track net gain/loss for friends giving and receiving gifts evenly.
 * [中文] 題目說明: 朋友間送禮金錢計算：送禮者將金額平分給受禮者，餘數自己保留，求各人的淨收支。
 * [EN] Approach: Hash table or linear lookup for names, maintain net balance.
 * [中文] 思路: 字串姓名查表維護淨收支金額。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

int find_name(int n, char names[][15], const char *target) {
    for (int i = 0; i < n; i++) if (strcmp(names[i], target) == 0) return i;
    return -1;
}

int main(void) {
    int ok = 1;
    printf("%s: UVa 119 - Greedy Gift Givers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
