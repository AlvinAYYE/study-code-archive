/*
 * LeetCode 0769. Max Chunks To Make Sorted（最多可分成幾塊排序）
 * 題意：arr 是 0..n-1 的排列；切成連續區塊、各自排序並串接後必須成為遞增陣列，求最多區塊數。
 * 範例：[4,3,2,1,0] -> 1；[1,0,2,3,4] -> 4。
 * 限制：1 <= n <= 10；元素是 0..n-1 的互異排列。
 * 解法：從左到右維護目前區間最大值；當最大值等於目前索引時，前綴剛好包含 0..index，可在此切開。
 * 複雜度：時間 O(n)，空間 O(1)。
 */
#include <stdbool.h>
#include <stdio.h>

/* ---- community solution ---- */
int maxChunksToSorted(int* arr, int arrSize) {
    int maximum = -1;
    int chunks = 0;
    for (int index = 0; index < arrSize; index++) {
        if (arr[index] > maximum) {
            maximum = arr[index];
        }
        if (maximum == index) {
            chunks++;
        }
    }
    return chunks;
}

/* ---- generated tests ---- */
int main(void) {
    int first[] = {4, 3, 2, 1, 0};
    int second[] = {1, 0, 2, 3, 4};
    int third[] = {0};
    bool passed = maxChunksToSorted(first, 5) == 1 &&
                  maxChunksToSorted(second, 5) == 4 &&
                  maxChunksToSorted(third, 1) == 1;
    printf("%s: 0769 maxChunksToSorted tests=3\n",
           passed ? "PASS" : "FAIL");
    return passed ? 0 : 1;
}
