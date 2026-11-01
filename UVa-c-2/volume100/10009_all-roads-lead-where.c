/*
 * ==========================================================================
 * UVa 10009 - All Roads Lead Where?
 * Title-CN: 條條大路通羅馬
 * Difficulty: UVa Star 1
 * Tags: tree, lca, graph, bfs
 * ==========================================================================
 * [EN] Problem: Given a tree of cities rooted at Rome, find the shortest path between any two cities.
 * [中文] 題目說明: 以羅馬 (Rome) 為根的城市樹狀圖中，求任兩城市之間的最短路徑（經最近公共祖先 LCA）。
 * [EN] Approach: Trace parents to root to find LCA, output path up and down.
 * [中文] 思路: 每個城市只有一個父節點，沿著父節點往上找到共同祖先，拼接上升與下降路徑。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

void solve_uva10009(char u, char v, const char parent[26], char *path) {
    char p1[30], p2[30];
    int l1 = 0, l2 = 0;
    char curr = u;
    while (curr != '\0') {
        p1[l1++] = curr;
        curr = parent[curr - 'A'];
    }
    curr = v;
    while (curr != '\0') {
        p2[l2++] = curr;
        curr = parent[curr - 'A'];
    }
    int i = l1 - 1, j = l2 - 1;
    while (i >= 0 && j >= 0 && p1[i] == p2[j]) {
        i--; j--;
    }
    int idx = 0;
    for (int k = 0; k <= i + 1; k++) path[idx++] = p1[k];
    for (int k = j; k >= 0; k--) path[idx++] = p2[k];
    path[idx] = '\0';
}

int main(void) {
    char parent[26] = {0};
    parent['B' - 'A'] = 'R'; /* R is root, B->R, C->R */
    parent['C' - 'A'] = 'R';
    char path[30];
    solve_uva10009('B', 'C', parent, path);
    int ok = (strcmp(path, "BRC") == 0);
    printf("%s: UVa 10009 - All Roads Lead Where\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
