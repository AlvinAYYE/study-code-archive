/*
 * ==========================================================================
 * UVa 165 - Frogs
 * Title-CN: 青蛙跳躍跳板連通性判斷
 * Difficulty: UVa Star 2
 * Tags: graph, flood-fill
 * URL: https://onlinejudge.org/external/1/165.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given coordinates of lily pads and frog jump range, determine if a path exists between start and destination pads.
 *
 * [中文] 題目說明:
 *     給定荷葉座標與青蛙最大跳躍距離，判定起始荷葉與目標荷葉之間是否存在連通跳躍路徑。
 *
 * [EN] Approach:
 *     Euclidean distance graph construction: add edge if distance <= jump range. Run BFS or DFS to test reachability.
 * [中文] 思路:
 *     計算荷葉兩兩間之歐幾里得距離，小於等於最大跳躍距者建立無向邊，以 BFS 或 DFS 判斷連通性。
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

int can_jump(double x1, double y1, double x2, double y2, double max_d) {
    double dx = x1 - x2, dy = y1 - y2;
    return (dx * dx + dy * dy) <= (max_d * max_d + 1e-9);
}

int main(void) {

    int ok = can_jump(0, 0, 3, 4, 5.0) && !can_jump(0, 0, 3, 4, 4.9);
    printf("%s: UVa 165 - Frogs\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
