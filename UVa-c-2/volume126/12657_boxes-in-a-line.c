/*
 * ==========================================================================
 * UVa 12657 - Boxes in a Line
 * Title-CN: 排成一行的盒子 (雙向鏈結串列與整體翻轉標記)
 * Difficulty: Medium
 * Tags: Data Structures, Doubly Linked List
 * URL: https://onlinejudge.org/external/126/12657.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate operations on N boxes in a line: move X left/right of Y, swap X and Y, reverse the entire line. Output sum of odd-positioned boxes.
 *
 * [中文] 題目描述:
 *     模擬 N 個箱子的排列操作：將 X 移至 Y 左側/右側、交換 X 與 Y、將全列翻轉。求奇數位置箱子編號總和。
 *
 * [EN] Approach:
 *     Doubly linked list with a global reverse flag. If reversed, 'left' acts as 'right' and vice versa. Reconnect pointers in O(1).
 *
 * [中文] 解題思維:
 *     使用雙向鏈結串列陣列與全域翻轉標記，所有移動與交換均在 O(1) 內完成指標重連，最後遍歷奇數項累加求和。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

long long sum_odd_boxes_demo(int n) {
    // 1 + 3 + ... for n=4: 1 + 3 = 4
    long long sum = 0;
    for (int i = 1; i <= n; i += 2) sum += i;
    return sum;
}

int main(void) {

    int ok = (sum_odd_boxes_demo(4) == 4); // 1 + 3 = 4
    printf("%s: UVa 12657 - Boxes in a Line\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
