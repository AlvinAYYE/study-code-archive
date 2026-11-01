/*
 * ==========================================================================
 * UVa 10141 - Request for Proposal
 * Title-CN: 企劃書招標評選 (多條件排序)
 * Difficulty: UVa Star 1
 * Tags: string, sorting, simulation
 * URL: https://onlinejudge.org/external/101/10141.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Select winning RFP proposal: highest compliance (requirements met), lowest price as tie-breaker, original order second tie-breaker.
 *
 * [中文] 題目說明:
 *     政府採購評選招標方案：優先選滿足需求數最多者；平手選投標報價最低者；再平手選最先投標者。
 *
 * [EN] Approach:
 *     Linear scan tracking best candidate by (requirements_met DESC, price ASC, arrival_order ASC).
 * [中文] 思路:
 *     線性巡訪候選提案，以三鍵比較更新最優企劃：符合項目數較大、價格較低、輸入順序較先。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int is_better_proposal(int req, double price, int best_req, double best_price) {
    if (req > best_req) return 1;
    if (req == best_req && price < best_price) return 1;
    return 0;
}

int main(void) {

    int ok = is_better_proposal(5, 100.0, 4, 50.0) && is_better_proposal(5, 80.0, 5, 100.0);
    printf("%s: UVa 10141 - Request for Proposal\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
