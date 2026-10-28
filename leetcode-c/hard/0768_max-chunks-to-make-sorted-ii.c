/*
 * LeetCode 768. Max Chunks To Make Sorted II
 * 題意（繁體中文）：把陣列切成最多個連續區塊，各區塊分別排序後再依序串接，
 * 要讓結果等於整個陣列排序後的結果。回傳最多可切成幾塊。陣列允許重複值。
 *
 * 範例：[5,4,3,2,1] -> 1；[2,1,3,4,4] -> 4。
 * 限制：陣列長度 1 到 2000；元素介於 0 到 10^8。
 * 解法：由右往左建立 suffixMin[i]，表示 i 及右側的最小值；由左往右維護
 *       prefixMax。若切點左側最大值 <= 右側最小值，兩邊排序後不會交錯，
 *       因此可以在此切開並增加一塊。最後一格必定形成最後一塊。
 * 複雜度：O(n) 時間、O(n) 額外空間。
 * LeetCode C API：int maxChunksToSorted(int* arr, int arrSize)
 */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int maxChunksToSorted(int* arr, int arrSize) {
    int *suffixMin = (int *)malloc((size_t)arrSize * sizeof *suffixMin);
    if (suffixMin == NULL) return 0;
    suffixMin[arrSize - 1] = arr[arrSize - 1];
    for (int i = arrSize - 2; i >= 0; --i)
        suffixMin[i] = arr[i] < suffixMin[i + 1] ? arr[i] : suffixMin[i + 1];

    int chunks = 0, prefixMax = INT_MIN;
    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] > prefixMax) prefixMax = arr[i];
        if (i == arrSize - 1 || prefixMax <= suffixMin[i + 1]) ++chunks;
    }
    free(suffixMin);
    return chunks;
}

int main(void) {
    int first[] = {5, 4, 3, 2, 1};
    int second[] = {2, 1, 3, 4, 4};
    int third[] = {1, 1, 0, 0, 1};
    int passed = maxChunksToSorted(first, 5) == 1 &&
                 maxChunksToSorted(second, 5) == 4 &&
                 maxChunksToSorted(third, 5) == 2;
    puts(passed ? "PASS: 768 max-chunks-to-make-sorted-ii"
                : "FAIL: 768 max-chunks-to-make-sorted-ii");
    return passed ? 0 : 1;
}
