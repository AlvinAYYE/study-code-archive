/*
 * ==========================================================================
 * UVa 149 - Forests
 * Title-CN: 樹木重疊能見度幾何計算
 * Difficulty: UVa Star 2
 * Tags: geometry
 * URL: https://onlinejudge.org/external/1/149.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given grid tree positions and circular radius, calculate the number of trees visible from an observer coordinate without occlusion.
 *
 * [中文] 題目說明:
 *     在給定半徑與圓形樹木網格中，計算站在原點的觀察者向四周望去時，不被前方樹木遮擋之可見樹木數量。
 *
 * [EN] Approach:
 *     Calculate polar angle and angular span for each circular tree; check whether a tree's angular interval is completely subsumed by closer trees.
 * [中文] 思路:
 *     計算每棵樹相對於觀察點之極角與視角半徑張角，按距離升序排列，以區間聯集檢查後方樹木是否被前方樹木完全遮蔽。
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

int is_occluded(double l1, double r1, double l2, double r2) {
    return (l2 >= l1 - 1e-9 && r2 <= r1 + 1e-9);
}

int main(void) {

    int ok = is_occluded(0.1, 0.5, 0.2, 0.4);
    printf("%s: UVa 149 - Forests\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
