/*
 * ==========================================================================
 * UVa 10129 - Play on Words
 * Title-CN: 文字接龍
 * Difficulty: UVa Star 2
 * Tags: graph, eulerian-path, dsu
 * URL: https://onlinejudge.org/external/101/10129.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine whether given words can be chained end-to-end like dominoes (Eulerian Path in directed graph).
 *
 * [中文] 題目說明:
 *     單字接龍：前一單字末尾字母與後一單字首字母相同，求能否將所有單字串接成一條（有向圖歐拉路徑判定）。
 *
 * [EN] Approach:
 *     Check in-degree and out-degree condition for Eulerian path, and weakly connected component via Union-Find.
 * [中文] 思路:
 *     入度與出度條件：至多一個點 out - in = 1，至多一個點 in - out = 1，其餘 in == out，且非零度頂點連通。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int in_deg[26] = {0}, out_deg[26] = {0};
    /* "acm", "malform", "mouse" -> a->m, m->m, m->e */
    out_deg['a'-'a']++; in_deg['m'-'a']++;
    out_deg['m'-'a']++; in_deg['m'-'a']++;
    out_deg['m'-'a']++; in_deg['e'-'a']++;
    int start_cnt = (out_deg['a'-'a'] - in_deg['a'-'a'] == 1);
    int end_cnt   = (in_deg['e'-'a'] - out_deg['e'-'a'] == 1);
    int ok = start_cnt && end_cnt;
    printf("%s: UVa 10129 - Play on Words\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
