/*
 * Title-CN: 多個陣列之間的最大距離
 * LeetCode 624. Maximum Distance in Arrays
 *
 * 題目翻譯：給定多個已遞增排序的陣列，從兩個不同陣列各選一個數字，
 * 使兩數差的絕對值最大。回傳這個最大距離。
 *
 * 例子：[[1,2,3],[4,5],[1,2,3]]，可取不同陣列中的 1 與 5，答案是 4。
 *
 * 限制：至少有兩個陣列；每個陣列已遞增排序；所有陣列總元素數最多 100000。
 *
 * 解題步驟：逐一走訪陣列，維護「之前所有陣列的最小值」與「之前所有陣列的最大值」。
 * 對目前陣列只需檢查兩種最遠組合：目前最大值減之前最小值，以及之前最大值減目前最小值。
 * 比較完才把目前陣列的首尾值納入全域最小/最大，確保兩個數來自不同陣列。
 *
 * 複雜度：每個陣列只讀首尾，時間 O(m)，額外空間 O(1)。
 *
 * LeetCode 提交區：保留 maxDistance 函式；main() 僅供本機測試。
 */

#include <assert.h>

int maxDistance(int **arrays, int arraysSize, int *arraysColSize) {
    int minimum = arrays[0][0];
    int maximum = arrays[0][arraysColSize[0] - 1];
    int answer = 0;

    for (int i = 1; i < arraysSize; ++i) {
        int currentMinimum = arrays[i][0];
        int currentMaximum = arrays[i][arraysColSize[i] - 1];
        int distance = currentMaximum - minimum;
        if (maximum - currentMinimum > distance) {
            distance = maximum - currentMinimum;
        }
        if (distance > answer) {
            answer = distance;
        }
        if (currentMinimum < minimum) {
            minimum = currentMinimum;
        }
        if (currentMaximum > maximum) {
            maximum = currentMaximum;
        }
    }
    return answer;
}

int main(void) {
    int row0[] = {1, 2, 3};
    int row1[] = {4, 5};
    int row2[] = {1, 2, 3};
    int *arrays[] = {row0, row1, row2};
    int sizes[] = {3, 2, 3};
    assert(maxDistance(arrays, 3, sizes) == 4);

    int one0[] = {1};
    int one1[] = {1};
    int *sameArrays[] = {one0, one1};
    int oneSizes[] = {1, 1};
    assert(maxDistance(sameArrays, 2, oneSizes) == 0);
    return 0;
}
