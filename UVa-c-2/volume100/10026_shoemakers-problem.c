/*
 * ==========================================================================
 * UVa 10026 - Shoemaker's Problem
 * Title-CN: 鞋匠的煩惱
 * Difficulty: UVa Star 2
 * Tags: greedy, sorting
 * URL: https://onlinejudge.org/external/100/10026.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Shoemaker has N jobs. Job i takes T_i days and incurs a fine of S_i per day of delay.
 *     Find the job sequence that minimizes total fine. If tied, pick smaller job index.
 *
 * [中文] 題目說明:
 *     鞋匠有 N 件工作，第 i 件工作需耗時 T_i 天，每延遲一天需支付罰款 S_i。
 *     求使總罰款最小的工作順序。若有多組最優順序，則按工作編號升序排列。
 *
 * [EN] Approach:
 *     Greedy exchange argument: job A before job B if T_A * S_B < T_B * S_A.
 *     Sort jobs using qsort with this comparator.
 * [中文] 思路:
 *     鄰項交換貪婪法：若 T_A * S_B < T_B * S_A，則先做 A 再做 B 罰款較少。依此比率排序。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int t;
    int s;
} Job;

static int cmp_job(const void *a, const void *b) {
    const Job *ja = (const Job *)a;
    const Job *jb = (const Job *)b;
    long long costA = (long long)ja->t * jb->s;
    long long costB = (long long)jb->t * ja->s;
    if (costA != costB) return (costA < costB) ? -1 : 1;
    return ja->id - jb->id;
}

void solve_uva10026(int n, Job *jobs, int *order) {
    qsort(jobs, (size_t)n, sizeof(Job), cmp_job);
    for (int i = 0; i < n; i++) order[i] = jobs[i].id;
}

int main(void) {
    Job jobs[4] = {
        {1, 3, 4},
        {2, 1, 1000},
        {3, 2, 2},
        {4, 5, 5}
    };
    int order[4];
    solve_uva10026(4, jobs, order);
    /* Job 2 has huge fine per day (ratio 1/1000), should be first */
    int ok = (order[0] == 2);
    printf("%s: UVa 10026 - Shoemakers Problem\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
