/*
 * LeetCode 0303. Range Sum Query - Immutable《區域和查詢－不可變》
 * 難度：Easy；標籤：陣列、設計、前綴和
 * 題目連結：https://leetcode.com/problems/range-sum-query-immutable/
 *
 * 題目說明：
 * 給定一個整數陣列 nums，建立 NumArray 資料結構，之後會多次詢問閉區間
 * [left, right] 中所有元素的總和。建立後 nums 不會修改。每次查詢都要包含
 * left 和 right 兩個位置。
 *
 * 範例：nums = [-2,0,3,-5,2,-1]
 * - sumRange(0, 2) = -2 + 0 + 3 = 1
 * - sumRange(2, 5) = 3 - 5 + 2 - 1 = -1
 * - sumRange(0, 5) = -2 + 0 + 3 - 5 + 2 - 1 = -3
 *
 * 限制：
 * - 1 <= nums.length <= 10^4
 * - -10^5 <= nums[i] <= 10^5
 * - 0 <= left <= right < nums.length
 * - sumRange 最多呼叫 10^4 次。
 *
 * 解題思路：
 * 1. 建構物件時建立前綴和 prefix，其中 prefix[i] 表示 nums 前 i 個元素的總和。
 *    prefix[0] 設為 0，方便處理從索引 0 開始的查詢。
 * 2. 區間 [left, right] 的總和等於 prefix[right + 1] - prefix[left]。
 *    前一項是從開頭加到 right，減掉 left 之前的部分就留下目標區間。
 * 3. 因此前綴和只需建立一次，每次查詢只做一次減法。
 *
 * 複雜度：建立時間 O(n)、額外空間 O(n)；每次 sumRange 時間 O(1)。
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *prefix;
    int size;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *obj = (NumArray*)malloc(sizeof(NumArray));
    int i;

    obj->prefix = (int*)malloc(sizeof(int) * (size_t)(numsSize + 1));
    obj->size = numsSize;
    obj->prefix[0] = 0;
    for (i = 0; i < numsSize; ++i) {
        obj->prefix[i + 1] = obj->prefix[i] + nums[i];
    }
    return obj;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return obj->prefix[right + 1] - obj->prefix[left];
}

void numArrayFree(NumArray* obj) {
    if (!obj) return;
    free(obj->prefix);
    free(obj);
}

int main(void) {
    int nums[] = {-2, 0, 3, -5, 2, -1};
    NumArray *obj = numArrayCreate(nums, 6);

    assert(numArraySumRange(obj, 0, 2) == 1);
    assert(numArraySumRange(obj, 2, 5) == -1);
    assert(numArraySumRange(obj, 0, 5) == -3);
    numArrayFree(obj);

    puts("PASS 0303 NumArray");
    return 0;
}
