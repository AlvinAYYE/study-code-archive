/*
 * ==========================================================================
 * UVa 119 - Greedy Gift Givers
 * Title-CN: 貪婪的送禮者
 * Difficulty: UVa Star 1
 * Tags: simulation, string
 * ==========================================================================
 * [EN] Problem: Track net gain/loss for friends giving and receiving gifts evenly.
 * [中文] 題目說明: 朋友間送禮金錢計算：送禮者將金額平分給受禮者，餘數自己保留，求各人的淨收支。
 * [EN] Approach: Hash table or linear lookup for names, maintain net balance.
 * [中文] 思路: 字串姓名查表維護淨收支金額。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

int find_name(int n, char names[][32], const char *target) {
    for (int i = 0; i < n; i++) if (strcmp(names[i], target) == 0) return i;
    return -1;
}

void solve_uva119(FILE *in, FILE *out) {
    int n;
    int first_group = 1;

    while (fscanf(in, "%d", &n) == 1) {
        char names[32][32];
        long balances[32] = {0};
        int i;

        if (n < 1 || n > 32) {
            return;
        }
        for (i = 0; i < n; i++) {
            fscanf(in, "%31s", names[i]);
        }

        for (i = 0; i < n; i++) {
            char giver[32];
            long amount;
            int recipient_count;
            int giver_index;
            int j;

            if (fscanf(in, "%31s %ld %d", giver, &amount, &recipient_count) != 3) {
                return;
            }
            giver_index = find_name(n, names, giver);
            if (giver_index < 0) {
                return;
            }

            if (recipient_count > 0) {
                long share = amount / recipient_count;
                balances[giver_index] -= share * recipient_count;
                for (j = 0; j < recipient_count; j++) {
                    char recipient[32];
                    int recipient_index;
                    fscanf(in, "%31s", recipient);
                    recipient_index = find_name(n, names, recipient);
                    if (recipient_index >= 0) {
                        balances[recipient_index] += share;
                    }
                }
            }
        }

        if (!first_group) {
            fputc('\n', out);
        }
        first_group = 0;
        for (i = 0; i < n; i++) {
            fprintf(out, "%s %ld\n", names[i], balances[i]);
        }
    }
}

int main(void) {
    solve_uva119(stdin, stdout);
    return 0;
}
