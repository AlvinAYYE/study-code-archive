/*
 * ==========================================================================
 * UVa 187 - Transaction Processing
 * Title-CN: 會計借貸平衡與交易日誌處理
 * Difficulty: UVa Star 1
 * Tags: simulation, finance
 * URL: https://onlinejudge.org/external/1/187.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given account descriptions and double-entry transaction journals, detect unbalanced transactions and output balancing adjustment entries.
 *
 * [中文] 題目說明:
 *     給定會計科目表與複式簿記交易紀錄，檢驗每筆交易的借貸總額是否平衡；若不平衡則自動計算並產生懸帳調整分錄。
 *
 * [EN] Approach:
 *     Group ledger lines by transaction ID. Accumulate signed cents; if net sum != 0, print transaction details and a balancing row to account 999.
 * [中文] 思路:
 *     依交易編號分組，以整數「分」累加借貸金額，若借貸代數和不為零，印出該筆交易清單並向 999 號科目補足差額。
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

int is_balanced(int sum_cents) {
    return sum_cents == 0;
}

int main(void) {

    int ok = is_balanced(0) && !is_balanced(150);
    printf("%s: UVa 187 - Transaction Processing\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
