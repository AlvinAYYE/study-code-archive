/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】選一種排序法，把整數由小到大排序。
 * 【輸入】n、n 個整數、排序法編號：1 泡沫、2 選擇、3 插入、4 快速、5 合併、6
 * 堆積。【輸出】排序後的 n 個數。 【閱讀順序】main 讀取數列與方法編號，再依 mode
 * 選擇對應演算法。泡沫排序比較相鄰值；選擇排序找未排序部分最小值；插入排序把目前值插入已排序前段；快速排序分割左右；合併排序分治後合併；堆積排序利用最大堆反覆取最大值。
 * 【C 語法】swap 用暫存變數交換兩數；遞迴 quick/merge 會處理子範圍；down 維持最大堆；malloc
 * 配置合併排序暫存陣列。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入 n、n 個整數、排序法編號：1泡沫 2選擇 3插入 4快速 5合併
 * 6堆積；輸出排序結果。 */
#include <stdio.h>
#include <stdlib.h>
#define N 200000
void swap(int *values, int *b) {
    int temporary_value = *values;
    *values = *b;
    *b = temporary_value;
}
void quick(int *values, int left, int right) {
    if (left >= right)
        return;
    int left_index = left, right_index = right, pivot = values[(left + right) / 2];
    while (left_index <= right_index) {
        while (values[left_index] < pivot)
            left_index++;
        while (values[right_index] > pivot)
            right_index--;
        if (left_index <= right_index)
            swap(&values[left_index++], &values[right_index--]);
    }
    if (left < right_index)
        quick(values, left, right_index);
    if (left_index < right)
        quick(values, left_index, right);
}
void merge(int *values, int *temporary_value, int left, int right) {
    if (right - left < 2)
        return;
    int middle = (left + right) / 2;
    merge(values, temporary_value, left, middle);
    merge(values, temporary_value, middle, right);
    int left_index = left, right_index = middle, k = left;
    while (left_index < middle || right_index < right)
        temporary_value[k++] = (right_index == right ||
                                (left_index < middle && values[left_index] <= values[right_index]))
                                   ? values[left_index++]
                                   : values[right_index++];
    for (left_index = left; left_index < right; left_index++)
        values[left_index] = temporary_value[left_index];
}
void down(int *values, int value_count, int left_index) {
    for (;;) {
        int child_index = 2 * left_index + 1;
        if (child_index >= value_count)
            return;
        if (child_index + 1 < value_count && values[child_index + 1] > values[child_index])
            child_index++;
        if (values[left_index] >= values[child_index])
            return;
        swap(&values[left_index], &values[child_index]);
        left_index = child_index;
    }
}
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    int value_count, sort_mode, values[N];
    if (scanf("%d", &value_count) != 1 || value_count < 0 || value_count > N)
        return 1;
    for (int left_index = 0; left_index < value_count; left_index++)
        if (scanf("%d", &values[left_index]) != 1)
            return 1;
    if (scanf("%d", &sort_mode) != 1)
        return 1;
    if (sort_mode == 1) {
        for (int left_index = 0; left_index < value_count; left_index++)
            for (int right_index = 0; right_index + 1 < value_count - left_index; right_index++)
                if (values[right_index] > values[right_index + 1])
                    swap(&values[right_index], &values[right_index + 1]);
    } else if (sort_mode == 2) {
        for (int left_index = 0; left_index < value_count; left_index++) {
            int middle = left_index;
            for (int right_index = left_index + 1; right_index < value_count; right_index++)
                if (values[right_index] < values[middle])
                    middle = right_index;
            swap(&values[left_index], &values[middle]);
        }
    } else if (sort_mode == 3) {
        for (int left_index = 1; left_index < value_count; left_index++) {
            int current_value = values[left_index], right_index = left_index;
            while (right_index && values[right_index - 1] > current_value)
                values[right_index] = values[right_index - 1], right_index--;
            values[right_index] = current_value;
        }
    } else if (sort_mode == 4)
        quick(values, 0, value_count - 1);
    else if (sort_mode == 5) {
        int *temporary_value = malloc((size_t)value_count * sizeof(int));
        if (!temporary_value)
            return 1;
        merge(values, temporary_value, 0, value_count);
        free(temporary_value);
    } else if (sort_mode == 6) {
        for (int left_index = value_count / 2 - 1; left_index >= 0; left_index--)
            down(values, value_count, left_index);
        for (int left_index = value_count - 1; left_index > 0; left_index--)
            swap(&values[0], &values[left_index]), down(values, left_index, 0);
    } else
        return puts("排序法編號錯誤"), 1;
    for (int left_index = 0; left_index < value_count; left_index++)
        printf("%d%c", values[left_index], left_index + 1 == value_count ? '\n' : ' ');
    return 0;
}
