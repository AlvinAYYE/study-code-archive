/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】比較線性搜尋、二分搜尋和插值搜尋找到目標值的位置。
 * 【輸入】n、目標值 target、n
 * 個整數。【輸出】線性搜尋在原陣列的位置，以及二分和插值搜尋在排序後陣列的位置；找不到回報 -1。
 * 【閱讀順序】先在讀入時記錄 target 第一次出現的原始索引。qsort 把 a
 * 排序。二分搜尋每次把範圍減半；插值搜尋依目標值在端點數值間的比例猜測位置。兩者都只適用已排序資料。
 * 【C 語法】cmp 是 qsort 要求的比較函式；return
 * (x>y)-(x<y) 會回傳正、負或 0；l、r、m
 * 分別代表搜尋區間左端、右端和中點。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入 n、target、n
 * 個整數；輸出線性搜尋原陣列位置，以及排序後二分與插值搜尋位置。 */
#include <stdio.h>
#include <stdlib.h>
#define N 1000000
int cmp(const void *first_item, const void *second_item) {
    int first_value = *(const int *)first_item, second_value = *(const int *)second_item;
    return (first_value > second_value) - (first_value < second_value);
}
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    int value_count, target_value, linear_result = -1;
    static int values[N], original_values[N];
    if (scanf("%d%d", &value_count, &target_value) != 2 || value_count < 1 || value_count > N)
        return 1;
    for (int index = 0; index < value_count; index++) {
        if (scanf("%d", &values[index]) != 1)
            return 1;
        original_values[index] = values[index];
        if (linear_result < 0 && values[index] == target_value)
            linear_result = index;
    }
    qsort(values, value_count, sizeof(int), cmp);
    int left = 0, right = value_count - 1, binary_result = -1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (values[middle] == target_value) {
            binary_result = middle;
            break;
        }
        if (values[middle] < target_value)
            left = middle + 1;
        else
            right = middle - 1;
    }
    left = 0;
    right = value_count - 1;
    int interpolation_result = -1;
    while (left <= right && target_value >= values[left] && target_value <= values[right]) {
        if (values[left] == values[right]) {
            if (values[left] == target_value)
                interpolation_result = left;
            break;
        }
        int middle = left + (int)((double)(right - left) * (target_value - values[left]) /
                                  (values[right] - values[left]));
        if (values[middle] == target_value) {
            interpolation_result = middle;
            break;
        }
        if (values[middle] < target_value)
            left = middle + 1;
        else
            right = middle - 1;
    }
    printf("線性搜尋原陣列索引：%d\n二分搜尋排序後索引：%d\n插值搜尋排序後索引：%d\n",
           linear_result,
           binary_result,
           interpolation_result);
    return 0;
}
