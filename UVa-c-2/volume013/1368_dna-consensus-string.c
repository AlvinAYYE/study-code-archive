/*
 * ==========================================================================
 * UVa 1368 - DNA Consensus String
 * Title-CN: DNA 共識字串
 * Difficulty: UVa Star 1
 * Tags: string, greedy
 * ==========================================================================
 * [EN] Problem: Find consensus DNA sequence minimizing total Hamming distance to m given sequences.
 * [中文] 題目說明: 給定 m 條長度 n 的 DNA 序列，求漢明距離和最小的共識字串（字母平手取 A, C, G, T 字典序）。
 * [EN] Approach: Greedy column-by-column majority vote.
 * [中文] 思路: 逐列統計 A, C, G, T 出現頻率，貪婪選取最高頻者。
 * ==========================================================================
 */
#include <stdio.h>

void solve_uva1368(int m, int n, char dna[][55], char *consensus, int *total_dist) {
    static const char bases[4] = {'A', 'C', 'G', 'T'};
    int dist = 0;
    for (int c = 0; c < n; c++) {
        int cnt[4] = {0};
        for (int r = 0; r < m; r++) {
            char b = dna[r][c];
            if (b == 'A') cnt[0]++;
            else if (b == 'C') cnt[1]++;
            else if (b == 'G') cnt[2]++;
            else if (b == 'T') cnt[3]++;
        }
        int max_b = 0;
        for (int b = 1; b < 4; b++) if (cnt[b] > cnt[max_b]) max_b = b;
        consensus[c] = bases[max_b];
        dist += (m - cnt[max_b]);
    }
    consensus[n] = '\0';
    *total_dist = dist;
}

int main(void) {
    char dna[3][55] = {
        "ATG",
        "ATG",
        "ACG"
    };
    char con[55];
    int d;
    solve_uva1368(3, 3, dna, con, &d);
    int ok = (d == 1);
    printf("%s: UVa 1368 - DNA Consensus String\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
