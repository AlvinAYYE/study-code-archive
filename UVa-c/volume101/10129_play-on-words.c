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
#include <string.h>

static int find_root(int parent[26], int x) {
    if (parent[x] != x) parent[x] = find_root(parent, parent[x]);
    return parent[x];
}

static void unite(int parent[26], int a, int b) {
    a = find_root(parent, a);
    b = find_root(parent, b);
    if (a != b) parent[b] = a;
}

static int can_order(const int in_degree[26], const int out_degree[26],
                     int parent[26], const int used[26]) {
    int starts = 0;
    int ends = 0;
    int component = -1;
    int i;

    for (i = 0; i < 26; ++i) {
        int difference = out_degree[i] - in_degree[i];
        if (difference == 1) {
            ++starts;
        } else if (difference == -1) {
            ++ends;
        } else if (difference != 0) {
            return 0;
        }

        if (used[i]) {
            int root = find_root(parent, i);
            if (component == -1) component = root;
            else if (component != root) return 0;
        }
    }
    return (starts == 0 && ends == 0) || (starts == 1 && ends == 1);
}

int solve(FILE *in, FILE *out) {
    int test_cases;
    int case_number;

    if (fscanf(in, "%d", &test_cases) != 1) return 0;
    for (case_number = 0; case_number < test_cases; ++case_number) {
        int in_degree[26] = {0};
        int out_degree[26] = {0};
        int used[26] = {0};
        int parent[26];
        int word_count;
        int i;
        char word[1024];

        for (i = 0; i < 26; ++i) parent[i] = i;
        if (fscanf(in, "%d", &word_count) != 1) return 1;
        for (i = 0; i < word_count; ++i) {
            size_t len;
            int first;
            int last;
            if (fscanf(in, "%1023s", word) != 1) return 1;
            len = strlen(word);
            first = word[0] - 'a';
            last = word[len - 1] - 'a';
            ++out_degree[first];
            ++in_degree[last];
            used[first] = used[last] = 1;
            unite(parent, first, last);
        }

        fprintf(out, "%s\n", can_order(in_degree, out_degree, parent, used)
                ? "Ordering is possible."
                : "The door cannot be opened.");
    }
    return 0;
}

int main(void) {
    return solve(stdin, stdout);
}
