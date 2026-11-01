/*
 * ==========================================================================
 * UVa 10114 - Loansome Car Buyer
 * Title-CN: 買車貸款折舊與負債平衡月數
 * Difficulty: UVa Star 1
 * Tags: simulation
 * URL: https://onlinejudge.org/external/101/10114.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate monthly car depreciation and loan repayment to find the first month where the car value exceeds the remaining loan amount.
 *
 * [中文] 題目說明:
 *     模擬每月車輛折舊與本金分期攤還，求出首個使汽車剩餘價值大於未償還貸款金額的月份。
 *
 * [EN] Approach:
 *     Maintain car value = (loan + down_payment) * (1 - dep[0]), then month by month apply loan -= payment and car_value *= (1 - dep[m]). Stop when car_value > loan.
 * [中文] 思路:
 *     第 0 個月車價乘上即時折舊率，其後每月依固定本金還款且車價按月折舊，記錄首次車價嚴格大於貸款餘額的月份。
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

int solve_uva10114(int dur, double down, double loan, int dep_cnt, int *dep_m, double *dep_r) {
    double rates[105];
    int cur_r_idx = 0;
    for (int m = 0; m <= dur; m++) {
        if (cur_r_idx + 1 < dep_cnt && dep_m[cur_r_idx + 1] <= m) {
            cur_r_idx++;
        }
        rates[m] = dep_r[cur_r_idx];
    }
    double monthly_pay = loan / dur;
    double car_val = (loan + down) * (1.0 - rates[0]);
    double cur_loan = loan;
    if (car_val > cur_loan) return 0;
    for (int m = 1; m <= dur; m++) {
        cur_loan -= monthly_pay;
        car_val *= (1.0 - rates[m]);
        if (car_val > cur_loan) return m;
    }
    return dur;
}

int main(void) {

    int dm[] = {0};
    double dr[] = {0.10};
    int m = solve_uva10114(10, 500, 1000, 1, dm, dr); // car=1350 > 1000 at m=0
    int ok = (m == 0);
    printf("%s: UVa 10114 - Loansome Car Buyer\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
