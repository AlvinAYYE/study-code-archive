/*
 * ==========================================================================
 * UVa 10491 - Cows and Cars
 * Title-CN: 蒙提霍爾三門問題廣義機率公式
 * Difficulty: UVa Star 1
 * Tags: math, probability
 * URL: https://onlinejudge.org/external/104/10491.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Generalize the Monty Hall problem: N doors with COWS cows and CARS cars. Host opens SHOW cows. You switch doors. Find probability of winning a car.
 *
 * [中文] 題目說明:
 *     廣義蒙提霍爾三門問題：共 N 扇門包含 COW 隻牛與 CAR 輛跑車，主持人開啟 SHOW 扇有牛的門，玩家換門後贏得跑車的機率。
 *
 * [EN] Approach:
 *     P(win) = P(pick cow initially)*P(switch to car) + P(pick car initially)*P(switch to car) = (COW/(COW+CAR))*(CAR/(TOTAL-SHOW-1)) + (CAR/TOTAL)*((CAR-1)/(TOTAL-SHOW-1)).
 * [中文] 思路:
 *     全機率公式：初選選中牛後換門中車 + 初選選中車後換門中車，兩條件機率加權求和。
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

double solve_uva10491(double cows, double cars, double show) {
    double total = cows + cars;
    double rem = total - show - 1.0;
    double p = (cows / total) * (cars / rem) + (cars / total) * ((cars - 1.0) / rem);
    return p;
}

int main(void) {

    double p = solve_uva10491(1, 1, 0); // 2 doors, 1 cow, 1 car, switch -> 0
    double p2 = solve_uva10491(2, 1, 1); // classic Monty Hall: 2/3
    int ok = (fabs(p2 - 2.0 / 3.0) < 1e-4);
    printf("%s: UVa 10491 - Cows and Cars\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
