/*
 * LeetCode 753. Cracking the Safe
 * 題意（繁體中文）：密碼長度為 n，每位數字可為 0 到 k-1。每輸入一位，
 * 保險箱就檢查最近 n 位。請回傳最短的輸入字串，使每一種長度 n 的密碼
 * 都至少在輸入過程中出現一次；符合條件的答案可以有很多種。
 *
 * 範例：n=1,k=2 -> "10"；n=2,k=2 -> "01100"（其他順序也可以）。
 * 限制：1 <= n <= 4、1 <= k <= 10、k^n <= 4096。
 * 解法：把每個 n-1 位字串視為圖上的節點，每條邊代表接上一個數字，
 *       因此每個可能密碼恰好是一條邊。用 DFS 做 Euler 路徑，讓每條邊只走一次；
 *       依走訪完成順序倒序輸出邊上的數字，再在前面補 n-1 個 0。
 * 複雜度：O(k^n) 時間與空間。
 * LeetCode C API：char* crackSafe(int n, int k)
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void visitEdges(int node, int n, int k, int nodeCount,
                       bool *visited, char *postorder, int *length) {
    for (int digit = 0; digit < k; ++digit) {
        int edge = node * k + digit;
        if (visited[edge]) continue;
        visited[edge] = true;
        int nextNode = edge % nodeCount;
        visitEdges(nextNode, n, k, nodeCount, visited, postorder, length);
        postorder[(*length)++] = (char)('0' + digit);
    }
}

char* crackSafe(int n, int k) {
    int edgeCount = 1, nodeCount = 1;
    for (int i = 0; i < n; ++i) edgeCount *= k;
    for (int i = 1; i < n; ++i) nodeCount *= k;

    bool visited[4096] = {false};
    char postorder[4096];
    int postorderLength = 0;
    visitEdges(0, n, k, nodeCount, visited, postorder, &postorderLength);

    int outputLength = edgeCount + n - 1;
    char *answer = (char *)malloc((size_t)outputLength + 1);
    if (answer == NULL) return NULL;
    for (int i = 0; i < n - 1; ++i) answer[i] = '0';
    for (int i = 0; i < edgeCount; ++i)
        answer[n - 1 + i] = postorder[edgeCount - 1 - i];
    answer[outputLength] = '\0';
    return answer;
}

static int includesEveryPassword(const char *sequence, int n, int k) {
    int combinations = 1;
    for (int i = 0; i < n; ++i) combinations *= k;
    if ((int)strlen(sequence) != combinations + n - 1) return 0;
    bool seen[4096] = {false};
    for (int start = 0; start < combinations; ++start) {
        int code = 0;
        for (int i = 0; i < n; ++i) {
            int digit = sequence[start + i] - '0';
            if (digit < 0 || digit >= k) return 0;
            code = code * k + digit;
        }
        if (seen[code]) return 0;
        seen[code] = true;
    }
    for (int code = 0; code < combinations; ++code)
        if (!seen[code]) return 0;
    return 1;
}

int main(void) {
    char *first = crackSafe(1, 2);
    char *second = crackSafe(2, 2);
    char *third = crackSafe(3, 2);
    int passed = first != NULL && second != NULL && third != NULL &&
                 includesEveryPassword(first, 1, 2) &&
                 includesEveryPassword(second, 2, 2) &&
                 includesEveryPassword(third, 3, 2);
    free(first);
    free(second);
    free(third);
    puts(passed ? "PASS: 753 cracking-the-safe" : "FAIL: 753 cracking-the-safe");
    return passed ? 0 : 1;
}
