/*
 * Title-CN: 區域和查詢（可修改）
 * LeetCode 307. Range Sum Query - Mutable
 *
 * 題目翻譯：設計一個資料結構，支援兩種操作：把某個位置的數字改成新值，
 * 以及查詢左右索引（含端點）之間的總和。
 *
 * 例子：nums = [1,3,5]，查詢 [0,2] 得 9；把索引 1 改成 2 後，查詢 [0,2] 得 8。
 *
 * 限制：最多 30000 個數字，最多進行 30000 次更新與查詢。
 *
 * 解題步驟：
 *   1. 用 Fenwick Tree（樹狀陣列）保存區間累積資訊，另存目前每個位置的值。
 *   2. 建立時先複製數字，再由小到大把每個樹狀區塊加進它的父區塊。
 *   3. 更新位置時算出「新值 - 舊值」，只沿著該位置負責的樹狀區塊往上更新。
 *   4. 前綴和用索引一路減去最低位元往回累加；區間和 = 右端前綴和 - 左端前一格前綴和。
 *
 * 複雜度：建立 O(n)，更新 O(log n)，查詢 O(log n)，額外空間 O(n)。
 *
 * LeetCode 提交區：保留 NumArray 與四個函式；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdlib.h>

typedef struct {
    int size;
    int *values;
    int *tree;
} NumArray;

static void add(NumArray *obj, int index, int delta) {
    for (int i = index + 1; i <= obj->size; i += i & -i) {
        obj->tree[i] += delta;
    }
}

static int prefixSum(const NumArray *obj, int endExclusive) {
    int sum = 0;
    for (int i = endExclusive; i > 0; i -= i & -i) {
        sum += obj->tree[i];
    }
    return sum;
}

NumArray *numArrayCreate(int *nums, int numsSize) {
    NumArray *obj = malloc(sizeof(*obj));
    if (obj == NULL) {
        return NULL;
    }
    obj->size = numsSize;
    obj->values = malloc((size_t)numsSize * sizeof(*obj->values));
    obj->tree = calloc((size_t)numsSize + 1, sizeof(*obj->tree));
    if (obj->values == NULL || obj->tree == NULL) {
        free(obj->values);
        free(obj->tree);
        free(obj);
        return NULL;
    }

    for (int i = 0; i < numsSize; ++i) {
        obj->values[i] = nums[i];
        obj->tree[i + 1] += nums[i];
        int parent = i + 1 + ((i + 1) & -(i + 1));
        if (parent <= numsSize) {
            obj->tree[parent] += obj->tree[i + 1];
        }
    }
    return obj;
}

void numArrayUpdate(NumArray *obj, int index, int val) {
    int delta = val - obj->values[index];
    obj->values[index] = val;
    add(obj, index, delta);
}

int numArraySumRange(NumArray *obj, int left, int right) {
    return prefixSum(obj, right + 1) - prefixSum(obj, left);
}

void numArrayFree(NumArray *obj) {
    if (obj != NULL) {
        free(obj->values);
        free(obj->tree);
        free(obj);
    }
}

int main(void) {
    int nums[] = {1, 3, 5};
    NumArray *obj = numArrayCreate(nums, 3);
    assert(obj != NULL);
    assert(numArraySumRange(obj, 0, 2) == 9);
    numArrayUpdate(obj, 1, 2);
    assert(numArraySumRange(obj, 0, 2) == 8);
    assert(numArraySumRange(obj, 1, 2) == 7);
    numArrayUpdate(obj, 0, -1);
    assert(numArraySumRange(obj, 0, 1) == 1);
    numArrayFree(obj);
    return 0;
}
