/*
 * LeetCode 546. Remove Boxes（移除盒子）
 *
 * 題意（繁體中文）：
 *   一排盒子以整數顏色表示。每次可以移除一段連續且顏色相同的 k 個盒子，
 *   得到 k*k 分；移除後左右兩側會接在一起。請選擇移除順序，使總分最高，
 *   並回傳最高分。
 *
 * 範例：
 *   1. boxes=[1,3,2,2,2,3,4,3,1]，回傳 23。先消除中間三個 2 得 9 分，再讓
 *      兩個 3 接在一起消除得 4 分，並可繼續合併兩端的 1 等，最高總分為 23。
 *   2. boxes=[1,1,1]，回傳 9，一次移除三個盒子。
 *   3. boxes=[1]，回傳 1。
 *
 * 限制：1 <= boxes.length <= 100；1 <= boxes[i] <= 100。
 *
 * 解題步驟：
 *   1. 定義 dfs(left,right,attached)：計算區間 [left,right] 的最高分，並把
 *      attached 個與 boxes[right] 同色的盒子視為已黏在區間右端。
 *   2. 先把右端連續同色盒子收成一組。作法一是直接移除右端這組，分數為
 *      (attached+1)^2，再加上左側區間的最佳分數。
 *   3. 也可以先移除右端與某個相同顏色 boxes[i] 之間的盒子，讓兩組合併。
 *      此時遞迴計算 [left,i]（多帶一個附加盒子）與中間 [i+1,right-1]。
 *   4. 將每個狀態的答案記憶起來，避免重複計算。
 *
 * 複雜度：狀態數 O(n^3)，每個狀態最多掃描 O(n) 個位置，時間 O(n^4)，
 *   記憶空間 O(n^3)，遞迴深度 O(n)。
 * LeetCode C API：int removeBoxes(int* boxes, int boxesSize)
 */
#include <stdio.h>
#include <stdlib.h>

static int memoIndex(int n, int left, int right, int attached) {
    return (left * n + right) * (n + 1) + attached;
}

static int bestScore(const int *boxes, int n, int left, int right,
                     int attached, int *memo) {
    if (left > right) return 0;

    /* 右端相鄰同色盒子等價於附加盒子，先合併可縮小狀態範圍。 */
    while (right > left && boxes[right] == boxes[right - 1]) {
        --right;
        ++attached;
    }

    int index = memoIndex(n, left, right, attached);
    if (memo[index] != -1) return memo[index];

    int groupSize = attached + 1;
    int answer = bestScore(boxes, n, left, right - 1, 0, memo) +
                 groupSize * groupSize;

    /* 把右端這組留到之後，與左側同色盒子合併後一次移除。 */
    for (int i = left; i < right; ++i) {
        if (boxes[i] != boxes[right]) continue;
        int score = bestScore(boxes, n, left, i, attached + 1, memo) +
                    bestScore(boxes, n, i + 1, right - 1, 0, memo);
        if (score > answer) answer = score;
    }

    memo[index] = answer;
    return answer;
}

int removeBoxes(int *boxes, int boxesSize) {
    if (boxesSize <= 0) return 0;
    int n = boxesSize;
    size_t stateCount = (size_t)n * (size_t)n * (size_t)(n + 1);
    int *memo = (int *)malloc(stateCount * sizeof *memo);
    if (memo == NULL) return 0;
    for (size_t i = 0; i < stateCount; ++i) memo[i] = -1;

    int answer = bestScore(boxes, n, 0, n - 1, 0, memo);
    free(memo);
    return answer;
}

int main(void) {
    int boxes1[] = {1, 3, 2, 2, 2, 3, 4, 3, 1};
    int boxes2[] = {1, 1, 1};
    int boxes3[] = {1};
    int boxes4[] = {1, 2, 1};
    int passed = removeBoxes(boxes1, 9) == 23 &&
                 removeBoxes(boxes2, 3) == 9 &&
                 removeBoxes(boxes3, 1) == 1 &&
                 removeBoxes(boxes4, 3) == 5;
    puts(passed ? "PASS: 546 remove-boxes" : "FAIL: 546 remove-boxes");
    return passed ? 0 : 1;
}
